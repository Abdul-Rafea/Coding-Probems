#include <iostream>

using namespace std;

int main() {
	int a = 1;
	int b = 2;
	int c = 3;
	int d = 4;
	
	int* ptr = &a;
	const int* c_i_ptr = &b;
	int* const i_c_ptr = &c;
	const int* const c_i_c_ptr = &d;

	cout << "Normal Pointer: " << ptr << endl;
	cout << "  -> value: " << *ptr << endl << endl;

	cout << "Constant Pointer: " << c_i_ptr << endl;;
	cout << "  -> valur: " << *c_i_ptr << endl;

	cout << "Pointer Constant: " << i_c_ptr << endl;
	cout << "  -> value: " << *i_c_ptr << endl;

	cout << "Constant Pointer Constant: " << c_i_c_ptr << endl;
	cout << "  -> value: " << *c_i_c_ptr << endl;

	return 0;
}