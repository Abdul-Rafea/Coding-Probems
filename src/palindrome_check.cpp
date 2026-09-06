#include <iostream>
#include <cmath>

using namespace std;

int main() {
	char choice = 'y';
	
	while (choice == 'y' || choice == 'Y') {
		int num, reversed_num = 0;

		cout << "Enter number: ";
		cin >> num;

		while (num != 0) {
			int temp_num;

			temp_num = num % 10; 
			num = num / 10;

			reversed_num = (reversed_num * 10) + temp_num;
		}

		cout << "\nReversed number: " << reversed_num;
		
		cout << "\n\nDo you want to resatrt program [y/n]: ";
		cin >> choice;
		system("cls");
	}
	return 0;
}