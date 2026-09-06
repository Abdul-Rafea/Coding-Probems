#include <iostream>

using namespace std;

const int ARRAY_SIZE = 30;

void print_array(int[], const int);
void print_hash_table(int[][ARRAY_SIZE], int);

int main() {
	
	int arr[ARRAY_SIZE] = { 2, 5, 5, 1, 4, 3, 5, 3, 3, 4,
			6, 7, 8, 9, 0, -2, -4, -4, -5, -2,
			-4, -4, 0, -5, -5, -9, -2, 5, 4, 3}, 
		hash_arr[2][ARRAY_SIZE] = {{},{}},
		hash_size = 0;

	cout << "Current Array: ";
	print_array(arr, ARRAY_SIZE);

	for (int index = 0; index < ARRAY_SIZE; index++) {
		bool is_found = false;

		for (int i = 0; i < hash_size; i++) {
			if (arr[index] == hash_arr[0][i]) {
				hash_arr[1][i]++;
				is_found = true;

				break;
			}
		}
		
		if (!is_found) {
			hash_arr[0][hash_size] = arr[index];
			hash_arr[1][hash_size]++;
			hash_size++;
		}
	}
	
	print_hash_table(hash_arr, hash_size);
}

void print_array(int arr[], const int ARRAY_SIZE) {
	for (int i = 0; i < ARRAY_SIZE; i++) {
		cout << arr[i] << " ";
	}
}

void print_hash_table(int hash_arr[][ARRAY_SIZE], int hash_size) {
	cout << "Recurring elements: ";
	for (int i = 0; i < hash_size; i++) {
		if (hash_arr[1][i] > 1) {
			cout << "\n -> " << hash_arr[0][i];
			cout << "\n -> " << "frequency = " << hash_arr[1][i];
			cout << "\n";
		}
	}
}