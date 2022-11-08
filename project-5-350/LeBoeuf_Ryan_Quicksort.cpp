#include <iostream>
#include <string>
#include <vector>

using namespace std;

void quicksort(vector<int> values, string inputFile, string outputFile) {

	cout << values.size() << endl;
	cout << inputFile << endl;
	cout << outputFile << endl;

}

int main(int argc, char** argv) {

    if (argc != 3) {
        // print usage
        cout << "Usage: ./start input.txt output.txt" << endl;
    } else {
        // do the thing
		vector<int> values;
		values.push_back(10);
		values.push_back(20);
		values.push_back(30);

		quicksort(values, argv[1], argv[2]);
    }

    return 0;
}
