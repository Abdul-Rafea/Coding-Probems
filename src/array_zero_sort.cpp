#include <iostream> 

using namespace std;

void print_array(int[], int);
int find_non_zero_index(int[], const int, int);
int find_zero_index(int[], const int, int);

int main() {
	const int ARRAY_SIZE = 10;
	int arr[ARRAY_SIZE] = { 1, 3, 0, 0, 0, 7, 0, 9, 8, 0 };

	cout << "Current Array: ";
	print_array(arr, ARRAY_SIZE);

	int non_zero_index = find_non_zero_index(arr, ARRAY_SIZE, 0);
	int processed_values = 0;
	while (non_zero_index != -1) {
		int zero_index = find_zero_index(arr, ARRAY_SIZE, processed_values);

		if (zero_index == -1) {
			break;
		}
		else {
			if (zero_index < non_zero_index) {
				arr[zero_index] = arr[non_zero_index];
				arr[non_zero_index] = 0;
				//processed_values++;
 			}
		}
		processed_values++;

		cout << "\n\Current Array: ";
		print_array(arr, ARRAY_SIZE);

		non_zero_index = find_non_zero_index(arr, ARRAY_SIZE, processed_values);
	}


	/*
	int zero_count = 0, skip_index = 0, non_zero_index = 0;

	// find the index of 1st non-zero (skipping already sorted count) number and store in `int index`
	// fint the index of 1st zero, and store in `int zero_index`
	// swap these

	// repeat above steps until no non-zero number is found
	for (int i = 0; i < ARRAY_SIZE; i++) {
		for (int index = skip_index; index < ARRAY_SIZE; index++) {
			if (arr[index] != 0) {
				non_zero_index = index;
				skip_index++;
				break;
			}
			else {
				zero_count++;
			}
		}

		if (zero_count > 0) {
			arr[skip_index - 1] = arr[non_zero_index];
			arr[non_zero_index] = 0;

			cout << "\nAfter chamge: ";
			print_array(arr, ARRAY_SIZE);
		}
	}
	*/

	return 0;
}

void print_array(int arr[], int array_size) {
	for (int i = 0; i < array_size; i++) {
		cout << arr[i] << " ";
	}
}

int find_non_zero_index(int arr[], const int SIZE, int start_index) {
	for (int i = start_index; i < SIZE; i++) {
		if (arr[i] != 0) {
			return i;
		}
	}
	return -1;
}

int find_zero_index(int arr[], const int SIZE, int start_index) {
	for (int i = start_index; i < SIZE; i++) {
		if (arr[i] == 0) {
			return i;
		}
	}
	return -1;
}
