#include <iostream>
using namespace std;

int main() {
	int num[10] = { 12, 58, 46, 74, 93, 22, 41, 130, 99, 100 },
		largest = INT32_MIN, smallest = INT32_MAX,
		sec_largest = INT32_MIN, sec_smallest = INT32_MAX;
		
	for (int i = 0; i < 10; i++) {
		int target = num[i];
		int temp_min = INT32_MIN, temp_max = INT32_MAX;
			
			
		if (target > largest) {
			temp_min = largest;
			largest = target;
				
			if (temp_min > sec_largest) {
				sec_largest = temp_min;
			}
		}
		else {
			if (target > sec_largest) {
				sec_largest = target;
			}
		}

		if (target < smallest) {
			temp_max = smallest;
			smallest = target;

			if (temp_max < sec_smallest) {
				sec_smallest = temp_max;
			}
		}
		else {
			if (target < sec_smallest) {
				sec_smallest = target;
			}
		}
	}

	cout << "Largest: " << largest;
	cout << "\nsmallest: " << smallest;
	cout << "\nSecond samllest: " << sec_smallest;
	cout << "\nSecond Largest: " << sec_largest;

	return 0;
}
