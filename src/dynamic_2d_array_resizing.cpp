#include <iostream>
#include <random>

using namespace std;

void fill_matrix(int**, int, int);
void print_matrix(int**, int, int);
void swap_rows(int**, int, int, int);

int main() {
	int rows, cols;

	cout << "Enter rows: ";
	cin >> rows;
	cout << "Enter columns: ";
	cin >> cols;

	int** matrix = new int*[rows];
	for (int i = 0; i < rows; i++) {
		matrix[i] = new int[cols];
	}

	fill_matrix(matrix, rows, cols);
	cout << "Current Matrix: -" << endl;
	print_matrix(matrix, rows, cols);

	int row_1, row_2;
	cout << "Enter 2 row numbers to swap: ";
	cin >> row_1;
	cin >> row_2;

	swap_rows(matrix, row_1, row_2, rows);
	cout << "After Row Swap: -" << endl;
	print_matrix(matrix, rows, cols);

	return 0;
}

void fill_matrix(int** matrix, int rows, int cols) {
	random_device rd;
	mt19937 gen(rd());

	uniform_int_distribution<int> distrib(0, 99);

	for (int row = 0; row < rows; row++) {
		for (int col = 0; col < cols; col++) {
			matrix[row][col] = distrib(gen);
		}
	}
}

void print_matrix(int** matrix, int rows, int cols) {
	for (int row = 0; row < rows; row++) {
		for (int col = 0; col < cols; col++) {
			cout << matrix[row][col] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void swap_rows(int** matrix, int row_1, int row_2, int rows) {
	while (true) {
		if (row_1 > rows || row_2 > rows) {
			cout << "ROWS DOES NOT EXIST!" << endl;
			cout << "Re-enter ror names: ";
			cin >> row_1;
			cin >> row_2;
		}
		else if (row_1 == row_2) {
			return;
		}
		else {
			break;
		}
	}

	row_1--;
	row_2--;

	int* temp_ptr = matrix[row_1];
	matrix[row_1] = matrix[row_2];
	matrix[row_2] = temp_ptr;
}
