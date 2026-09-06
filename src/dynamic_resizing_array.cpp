#include <iostream>

using namespace std;

void copy_old_to_new(int*, int*, int);
void print_array(int*, int);
void resize_and_copy(int*&, int);

int main() {
	int size;
	cout << "Enter array size: "; 
	cin >> size;
	
	int* arr = new int[size] {};
	int index = 0;

	while (true) {
		cout << "Enter value for array[" << index << "] or -1 to exit: ";
		//cin >> *(arr_ptr + index);
		cin >> arr[index];
		
		if (arr[index] == -1) {
			break;
		}
		
		index++;

		//resizing array
		if (index == size) {
			size = size * 2;
			resize_and_copy(arr, size);
		}
	}

	print_array(arr, index);
	delete arr;

	arr = nullptr;

	return 0;
}

void copy_old_to_new(int* arr_ptr, int* new_arr_ptr, int arr_size) {

	for (int index = 0; index < arr_size; index++) {
		*(new_arr_ptr + index) = *(arr_ptr + index);
	}
}

void print_array(int* arr_ptr, int arr_size) {
	cout << endl;
	for (int index = 0; index < arr_size; index++) {
		cout << *(arr_ptr + index) << ", ";
	}
	cout << endl;
}

void resize_and_copy(int* &arr, int size) {
	int* temp_arr_ptr = new int[size] {};
	copy_old_to_new(arr, temp_arr_ptr, size);

	delete arr;
	arr = temp_arr_ptr;
	cout << endl << "  -> array resized to doube its size" << endl;

	temp_arr_ptr = nullptr;
}