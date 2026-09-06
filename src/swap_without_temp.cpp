#include <iostream>

using namespace std;

void swap_single_ptr(int*, int*);
void swap_double_ptr(int**, int**);

int main() {
	int a = 5, b = 10;
	int* ptr_1 = &a;
	int* ptr_2 = &b;
	int** db_ptr_1 = &ptr_1;
	int** db_ptr_2 = &ptr_2;

	cout << "Before Swaping: " << endl;
	cout << "  -> a = " << a << ", b = " << b << endl << endl;

	swap_single_ptr(ptr_1, ptr_2);
	cout << "After single pointer swap: " << endl;
	cout << "  -> a = " << a << ", b = " << b << endl;

	swap_double_ptr(db_ptr_1, db_ptr_2);
	cout << "After double pointer swap: " << endl;
	cout << "  -> a = " << a << ", b = " << b << endl;

	return 0;
}

void swap_single_ptr(int* ptr_1, int* ptr_2) {
	int temp = *ptr_1;
	
	*ptr_1 = *ptr_2;
	*ptr_2 = temp;
}

void swap_double_ptr(int** ptr_1, int** ptr_2) {
	int temp = *(*ptr_1);

	*(*ptr_1) = *(*ptr_2);
	*(*ptr_2) = temp;
}
