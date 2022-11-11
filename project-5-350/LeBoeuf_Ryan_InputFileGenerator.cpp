#include <fstream>
#include <iostream>
#include <vector>
#include <iomanip>
#include <string>

#define NUM_FILES 25
#define BOUND 500
#define FLOAT_PRECISION 5

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

void generate_files(std::vector<int> input_sizes) {
    for (auto a = input_sizes.begin(); a != input_sizes.end(); a++) {
        std::string filename;
        int input_size = *a;

        for (int i = 0; i < NUM_FILES; i++) {
            filename = std::to_string(input_size) + "_" + std::to_string(i) + ".txt";
            std::cout << filename << std::endl;
            std::ofstream file(filename);

            std::vector<float> values = random_float(input_size);
            vector_to_file(file, values);

            file.close();
        }
    }    
}

int main(int argc, char** argv) {
    std::vector<int> input_sizes({10,100,1000});
    generate_files(input_sizes);

    return 0;
}