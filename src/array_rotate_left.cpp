#include <iostream>

using namespace std;

void print_array(int array[], const int ARRAY_SIZE) {
	for (int a = 0; a < ARRAY_SIZE; a++) {
		cout << array[a] << " ";
	}
}

int main() {
	char choice = 'y';
	const int ARRAY_SIZE = 10;

	while (choice == 'y' || choice == 'Y') {
		int num[ARRAY_SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0}, range, loop_count = 0;
		bool error_check = true;
		
		cout << "Current Array: ";
		print_array(num, ARRAY_SIZE);

		cout << "\nEnter range to rotate left: ";
		cin >> range;

		while (error_check) {
			if (range < 0) {
				cout << "\nError: Range must not be negative";
				cout << "\nRe-enter range: ";
				cin >> range;
			}
			else {
				error_check = false;
			}
		}

		for (int x = 0; x < range % ARRAY_SIZE; x++) {
			int first_num = num[0], temp_num;

			for (int y = ARRAY_SIZE - 1; y >= 0; y--) {
				temp_num = num[y];
				num[y] = first_num;
				first_num = temp_num;

				loop_count++;
			}
		}

		cout << "New Array: ";
		print_array(num, ARRAY_SIZE);
		cout << "\nLoop count: " << loop_count;

		cout << "\n\nDo you want to restart program [y/n]: ";
		cin >> choice;
		system("cls");
	}
	return 0;
}
