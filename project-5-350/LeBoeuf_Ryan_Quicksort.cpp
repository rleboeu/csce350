#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>

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

int main(int argc, char** argv) {

	std::vector<float> buffer({ 40.23, 30, 20, 50, 10.24353 });

	quicksort(buffer, 0, buffer.size()-1);
	
	print_array(buffer);

    return 0;
}
