#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>

#define FLOAT_PRECISION 5
#define USAGE "USAGE: ./start input.txt output.txt"

int partition(std::vector<float> &arr, int low, int high) {
	int pivot = arr.at(high);
	int i = (low - 1);

	for (int j = low; j <= high-1; j++) {
		if (arr.at(j) <= pivot) {
			i++;
			std::iter_swap(arr.begin() + i, arr.begin() + j);
		}
	}

	std::iter_swap(arr.begin() + (i+1), arr.begin() + high);
	return (i+1);
}

void quicksort(std::vector<float> &arr, int low, int high) {
	if (low < high) {
		int pivot = partition(arr, low, high);
		quicksort(arr, low, pivot-1);
		quicksort(arr, pivot+1, high);
	}
}

void print_array(std::vector<float> arr) {
	for (auto a = arr.begin(); a != arr.end(); a++) {
		std::cout << *a << std::endl;
	}
	std::cout << std::endl;
}

// split a string delimited by space into vector 
std::vector<std::string> split(std::string s)
{
    std::stringstream ss(s);
    std::string word;
	std::vector<std::string> tokens;

    while (ss >> word) {
        tokens.push_back(word);
    }

	return tokens;
}

// assume file is already open
void vector_to_file(std::ofstream &file, std::vector<float> arr) {
	int before_last = arr.size()-1;
	for (auto a = arr.begin(); a != arr.end(); a++) {
		file << std::fixed << std::setprecision(FLOAT_PRECISION) << *a;

		if (std::distance(arr.begin(), a) < before_last) {
			file << " ";
		}
	}
}

std::vector<float> file_to_vector(std::ifstream &file) {
	std::vector<std::string> tokens;
	std::vector<float> values;
	std::string line;

	std::getline(file, line);
	tokens = split(line);

	for (std::string s : tokens) {
		values.push_back(std::stof(s));
	}	

	return values;
}

int main(int argc, char** argv) {

	if (argc != 3) {
		fprintf(stderr, "ERROR: Invalid number of arguments!\n%s\n", USAGE);
		return 1;
	}

	std::ofstream output(argv[2]);
	std::ifstream input(argv[1]);

	//std::vector<float> buffer({ 40.23, 30, 20, 50, 10.24353 });
	std::vector<float> buffer = file_to_vector(input);

	quicksort(buffer, 0, buffer.size()-1);
	
	print_array(buffer);

	vector_to_file(output, buffer);

	input.close();
    output.close();
	
	return 0;
}
