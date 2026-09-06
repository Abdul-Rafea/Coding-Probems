#include <iostream>

using namespace std;

const int COLS = 5;

void print_matrix(int[][COLS], const int);
int no_of_digits(int num);

int main() {
	const int ROWS = 5;
	int array1[10] = { 1, 3, 5, 7, 9 };
	int array2[5] = { 2, 4, 6, 8, 10 };

	//int matrix[ROWS][COLS] = {
	//	{1, 2, 3},
	//	{4, 5, 6},
	//	{7, 8, 9},
	//};

	int matrix[ROWS][COLS] = {
		{1, 1, 1, 1, 1},
		{2, 2, 2, 2, 2},
		{3, 3, 3, 3, 3},
		{4, 4, 4, 4, 4},
		{5, 5, 5, 5, 5}
	};
	
	cout << "Before Transpose: -\n\n";
	print_matrix(matrix, ROWS);

	for (int row = 0; row < ROWS; row++) {
		for (int col = row; col < COLS; col++) {
			if (row == col) {
				continue;
			}
			int temp_entry = matrix[row][col];

			matrix[row][col] = matrix[col][row];
			matrix[col][row] = temp_entry;
		}
	}

	cout << "\n\nAfter Transpose: -\n\n";
	print_matrix(matrix, ROWS);

	return 0;
}

int no_of_digits(int num) {
	if (num == 0) {
		return 1;
	}

	int count = 0;

	while (num != 0) {
		num = num / 10;
		count++;
	}

	return count;
}

void print_matrix(int matrix[][COLS], const int ROWS) {
	int max_digits = 0;

	for (int row = 0; row < ROWS; row++) {
		for (int col = 0; col < COLS; col++) {
			int num_of_digits = no_of_digits(matrix[row][col]);

			if (num_of_digits > max_digits) {
				max_digits = num_of_digits;
			}
		}
	}

	for (int x = 0; x <= (max_digits + 3) * COLS; x++) {
		cout << "-";
	}
	for (int row = 0; row < ROWS; row++) {
		cout << "\n|";

		for (int col = 0; col < COLS; col++) {
			int sapces = (max_digits - no_of_digits(matrix[row][col]));

			for (int y = 0; y < sapces; y++) {
				cout << " ";
			}

			cout << " " << matrix[row][col];
			cout << " |";
		}

		cout << "\n";
		for (int x = 0; x <= (max_digits + 3) * COLS; x++) {
			cout << "-";
		}
	}
}
