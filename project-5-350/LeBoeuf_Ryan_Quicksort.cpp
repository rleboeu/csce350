#include "LeBoeuf_Ryan_Quicksort.h"

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
