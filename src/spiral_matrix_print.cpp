#include <iostream>

using namespace std;

const int COLS = 8;

int no_of_digits(int);
void print_matrix(int[][COLS], const int, const int);

int main() {
	const int ROWS = 8;

	//int matrix[ROWS][COLS] = {
	//	{1, 2, 3, 4},
	//	{12, 13, 14, 5},
	//	{11, 16, 15, 6},
	//	{10, 9, 8, 7}
	//};

	int matrix[ROWS][COLS] = {
		{ 1,  2,  3,  4,  5,  6, 7,   8},
		{28, 29, 30, 31, 32, 33, 34,  9},
		{27, 48, 49, 50, 51, 52, 35, 10},
		{26, 47, 60, 61, 62, 53, 36, 10001},
		{25, 46, 59, 64, 63, 54, 37, 12},
		{24, 45, 58, 57, 56, 55, 38, 13},
		{23, 44, 43, 42, 41, 40, 39, 14},
		{22, 21, 20, 19, 18, 17, 16, 15}
	};

	print_matrix(matrix, ROWS, COLS);

	int smaller = ROWS < COLS ? ROWS : COLS;
	// even numbers take exactly half, odd numbers take half + 1
	int loop_count = (smaller + 1) / 2;

	cout << "\n\n";
	for (int i = 0; i < loop_count; i++) {
		for (int col = i; col < COLS - i; col++) {
			cout << matrix[i][col] << " ";
		}
		for (int row = i + 1; row < ROWS - i; row++) {
			cout << matrix[row][(COLS - 1) - i] << " ";
		}
		for (int col = (COLS - 2) - i; col >= i; col--) {
			cout << matrix[(ROWS - 1) - i][col] << " ";
		}
		for (int row = (ROWS - 2) - i; row > i; row--) {
			cout << matrix[row][i] << " ";
		}
	}
	cout << "\n\n";

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

void print_matrix(int matrix[][COLS], const int ROWS, const int COLS) {
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
