#include "LeBoeuf_Ryan_InputFileGenerator.h"

#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>

void vector_to_file(std::ofstream& file,std::vector<float> arr) {
	int before_last = arr.size()-1;
	for (auto a = arr.begin(); a != arr.end(); a++) {
		file << std::fixed << std::setprecision(FLOAT_PRECISION) << *a;

		if (std::distance(arr.begin(), a) < before_last) {
			file << " ";
		}
	}
}

std::vector<float> random_float(int input_size) {
    std::vector<float> values;
    float generated;

    for (int i = 0; i < input_size; i++) {
        generated = float(std::rand())/float((RAND_MAX)) * BOUND;
        if ((float(std::rand())/float((RAND_MAX)) * 1.0) >= 0.5) {
            generated *= -1.0;
        }

        values.push_back(generated);
    }

    return values;
}

std::vector<std::vector<float>> generate_datasets(std::vector<int> input_sizes) {
    std::vector<std::vector<float>> datasets;
    
    for (auto a = input_sizes.begin(); a != input_sizes.end(); a++) {
        int input_size = *a;

        for (int i = 0; i < NUM_SETS; i++) {
            datasets.push_back(random_float(input_size));
        }
    }

    return datasets;
}

// split a string delimited by space into vector 
std::vector<std::string> split(std::string s) {
    std::stringstream ss(s);
    std::string word;
	std::vector<std::string> tokens;

    while (ss >> word) {
        tokens.push_back(word);
    }

	return tokens;
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