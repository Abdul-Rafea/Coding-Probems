#include <iostream>

using namespace std;

int main() {
	int num;
	char choice = 'y';

	while (choice == 'y' || choice == 'Y') {
		cout << "Enter number: ";
		cin >> num;

		if (num <= 0) {
			cout << "\nInvalid Input, try again.\n\n";
			continue;
		}

		for (int x = 1; x <= num; x++) {
			for (int y = 1; y <= num; y++) {
				cout << "*";
			}
			cout << "\n";
		}

		cout << "\nDo you want to restart program [y/n]: ";
		cin >> choice;

		system("cls");
	}

	return 0;
}
