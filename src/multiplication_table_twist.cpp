#include <iostream>

using namespace std;

int main() {
	int num, start_range, end_range;
	char choice = 'y';

	while (choice == 'y' || choice == 'Y') {
		cout << "Enter number: ";
		cin >> num;
		cout << "Enter stat range: ";
		cin >> start_range;
		cout << "Enter end range: ";-
		cin >> end_range;
		
		for (start_range; start_range <= end_range; start_range++) {
			int product = num * start_range;

			if ((product % 15) == 0) {
				continue;
			}

			cout << num << " x " << start_range << " = " << product << "\n";
		}

		cout << "\nDo you want to restart program [y/n]: ";
		cin >> choice;
	}
	
	return 0;
}
