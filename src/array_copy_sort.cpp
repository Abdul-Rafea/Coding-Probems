#include <iostream>

using namespace std;

void print_array(int[], const int);
void shift_array(int[], int, const int);

int main() {
	const int ARRAY_SIZE = 10;
	int arr_1[ARRAY_SIZE] = { -10, -9, -8, -7, -6, INT32_MAX, INT32_MAX, INT32_MAX, INT32_MAX, INT32_MAX}, arr_2[5] = { 0, 2, 3, 6, INT32_MAX - 1 },
		skip_index = 0;
	
	for (int index = 0; index < 5; index++) {
		int picked_value = arr_2[index];

		for (int i = skip_index; i < ARRAY_SIZE ; i++) {
			if (i == 0 && picked_value < arr_1[i]) {
				shift_array(arr_1, i, ARRAY_SIZE);
				arr_1[i] = picked_value;
				
				break;
			}
			if (i == ARRAY_SIZE - 1) {
				arr_1[ARRAY_SIZE - 1] = picked_value;

				break;
			}
			if ((picked_value >= arr_1[i]) && (picked_value <= arr_1[i + 1])) {
				shift_array(arr_1, i + 1, ARRAY_SIZE);
				arr_1[i + 1] = picked_value;
				skip_index = i + 1;

				break;
			}
		}
		cout << "\nItteration " << index + 1 << " : ";
		print_array(arr_1, ARRAY_SIZE);
		cout << "\n\n";
	}

	return 0;
}

void print_array(int arr[], const int ARRAY_SIZE) {
	for (int i = 0; i < ARRAY_SIZE; i++) {
		cout << arr[i] << " ";
	}
}

void shift_array(int arr[], int index, const int ARRAY_SIZE) {
	for (int i = 1; i < ARRAY_SIZE - index; i++) {
		arr[ARRAY_SIZE - i] = arr[(ARRAY_SIZE - 1) - i];
	}

	cout << "\nAfter shift: " ;
	print_array(arr, ARRAY_SIZE);
}