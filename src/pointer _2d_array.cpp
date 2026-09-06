#include <iostream>

using namespace std;

void print_array(int**, const int, const int);

int main() { 
	int ROWS = 3;
	int COLS = 3;
	
	// memory allocation
	int** arr = new int*[ROWS];
	for (int i = 0; i < ROWS; i++) {
		// arr[i] / *(arr + i)
		arr[i] = new int[COLS];

		for (int j = 0; j < COLS; j++) {
			arr[i][j] = (i + 1) + (j + 1);
		}
	}

	for (int x = 0; x < ROWS; x++) {
		int* ptr = *(arr + x);

		for (int y = 0; y < COLS; y++) {
			cout << *(ptr + y) << " ";
			
		}
		cout << endl;
	}

	return 0;
}
