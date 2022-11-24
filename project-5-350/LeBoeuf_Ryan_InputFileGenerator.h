#pragma once

#include <fstream>
#include <vector>
#include <string>

#define FLOAT_PRECISION 5
#define NUM_SETS 25
#define BOUND 500

void vector_to_file(std::ofstream& file,std::vector<float> arr);
std::vector<std::string> split(std::string s);
std::vector<float> file_to_vector(std::ifstream &file);
std::vector<std::vector<float>> generate_datasets(std::vector<int> input_sizes);
std::vector<std::string> split(std::string s);