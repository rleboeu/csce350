#include "LeBoeuf_Ryan_Quicksort.h"
#include "LeBoeuf_Ryan_InputFileGenerator.h"

#include <iostream>
#include <sstream>
#include <chrono>
#include <iomanip>

typedef struct exec_t {
	int input_size;
	float exec_time;
} exec_t;

int main(int argc, char** argv) {

	std::ofstream execfile("LeBoeuf_Ryan_averageExecutionTime.txt");
	std::ofstream agg_execfile("LeBoeuf_Ryan_executionTime.txt");

	std::string outfile_prefix = "outputs/output_";
	std::string infile_prefix = "inputs/input_";

	std::vector<int> input_sizes({ 10, 100, 1000 });
	std::vector<std::vector<float>> data_sets = generate_datasets(input_sizes);
	std::vector<exec_t> execution_times;
	std::vector<exec_t> aggregate_exec_times;

	// initialize the execution_times array
	for (auto a = input_sizes.begin(); a != input_sizes.end(); a++) {
		exec_t et;
		et.exec_time = 0.0;
		et.input_size = *a;
		execution_times.push_back(et);
	}

	int counter = 0;
	std::string file_postfix;
	for (auto a = data_sets.begin(); a != data_sets.end(); a++) {

		file_postfix = std::to_string(counter / NUM_SETS) + "_" + std::to_string(counter % NUM_SETS) + ".txt";

		// save unsorted dataset to file
		std::ofstream outfile(infile_prefix + file_postfix);
		vector_to_file(outfile, *a);
		outfile.close();

		// sort the input dataset
		auto start = std::chrono::high_resolution_clock::now();
		quicksort(*a, 0, (a->size()) - 1);
		auto stop = std::chrono::high_resolution_clock::now();
		float exec_time = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count() / 1000.0;
		
		// log the execution time
		execution_times.at(counter / NUM_SETS).exec_time += exec_time;
		
		exec_t time;
		time.exec_time = exec_time;
		time.input_size = execution_times.at(counter / NUM_SETS).input_size;
		aggregate_exec_times.push_back(time);

		// save sorted dataset to file
		std::ofstream outfile2(outfile_prefix + file_postfix);
		vector_to_file(outfile2, *a);
		outfile2.close();

		counter++;
	}

	// Log average execution times
	for (auto a = execution_times.begin(); a != execution_times.end(); a++) {
		a->exec_time /= NUM_SETS;

		execfile << a->input_size << "    " << a->exec_time;

		if (a != execution_times.end() - 1) {
			execfile << "\n";
		}
	}

	// Log aggregate execution times
	for (auto a = aggregate_exec_times.begin(); a != aggregate_exec_times.end(); a++) {
		agg_execfile << a->input_size << "    " << a->exec_time;

		if (a != aggregate_exec_times.end() - 1) {
			agg_execfile << "\n";
		}
	}

	execfile.close();
	agg_execfile.close();
}
