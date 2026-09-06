#include <iostream>

using namespace std;

int main() {
	int num;
	char choice = 'y';

	while (choice == 'y' || choice == 'Y') {
		int count = 0;
		cout << "Enter number: ";
		cin >> num;

		if (num <= 0) {
			cout << "\nInvalid Input, try again.\n\n";
			continue;
		}

		for (int x = 1; x <= num; x++) {
			for (int a = 1; a <= (num - x); a++) {
				cout << " ";
			}
			for (int y = 1; y <= x + count; y++) {
				cout << "*";
			}

			cout << "\n";
			count++;
		}

		count = (num - 2);

		for (int z = 1; z <= (num - 1); z++) {
			for (int b = 1; b <= z; b++) {
				cout << " ";
			}
			for (int i = ((num - z) + count); i >= 1; i--) {
				cout << "*";
			}

			cout << "\n";
			count--;
		}

		cout << "\nDo you want to restart program [y/n]: ";
		cin >> choice;

		system("cls");
	}

	return 0;
}
