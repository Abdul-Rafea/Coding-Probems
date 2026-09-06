#include <iostream>

using namespace std;

int main() {
	int num;
	char choice = 'y';

	while (choice == 'y' || choice == 'Y') {
		int count = 0;

		cout << "Enter a integer: ";
		cin >> num;

		if (num == 0) {
			count = 1;
		}
		else {
			while (num != 0) {
				num = num / 10;
				count++;
			}
		}

		cout << "\nNumber of digits: " << count;

		cout << "\n\nDo you want to restart program [y/n]: ";
		cin >> choice;

		system("cls");
	}
}
