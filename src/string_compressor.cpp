#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int size_of_string(char[]);
void shift_string_left(char[], int, int);
void shift_string_right(char[], int, int);
int no_of_digits(int);
int power(int, int);
int compress_string(char[], int, int, int);

int main() {
	char str[100] = "effffff" ;
	int str_size = size_of_string(str);
	char old_str[100];
	strcpy_s(old_str, str);

	if (str_size == 0) {
		cout << "Error: empty string";
		return 0;
	}
	else if (str_size < 2) {
		cout << "Compressed String: " << str;
		return 0;
	}

	int start_index = 0, end_index = 1;
	int new_str_size = str_size;

	while (str[start_index] != '\0') {
		if (str[start_index] == str[end_index]) {
			end_index++;
			continue;
		}

		//print_str(str, start_index, index);
		start_index = compress_string(str, start_index, end_index, str_size);
		new_str_size = size_of_string(str);
		end_index = start_index + 1;
		cout << "String Now: " << str << endl;
	}

	cout << "Compressed String: ";
	if (new_str_size > str_size) {
		cout << old_str;
	}
	else {
		cout << str;
	}
	

	return 0;
}

int size_of_string(char str[]) {
	int size = 0;
	while (str[size] != '\0') {
		size++;
	}
	return size;
}

void shift_string_left(char str[], int start_index, int end_index) {
	while (str[end_index] != '\0') {
		str[start_index + 1] = str[end_index];

		start_index++;
		end_index++;
	}
	str[start_index + 1] = '\0';
}

void shift_string_right(char str[], int start_index, int str_size) {
	for (int i = str_size; i > start_index; i--) {
		str[i + 1] = str[i];
	}
}

int no_of_digits(int num) {
	int digit_count = 0;
	while (num != 0) {
		digit_count++;
		num = num / 10;
	}
	return digit_count;
}

int power(int base, int power) {
	if (power == 0) {
		return 1;
	}

	int result = 10;
	for (int i = 1; i < power; i++) {
		result = result * base;
	}

	return result;
}

int compress_string(char str[], int start_index, int end_index, int str_size) {
	int char_count = end_index - start_index;

	if (char_count == 1) {
		shift_string_right(str, start_index, str_size);
		str[start_index + 1] = 1 + '0';
		return start_index + 2;
	}

	int digit_count = no_of_digits(char_count);
	char num_str[5];

	if (digit_count == 1) {
		num_str[0] = char_count + '0';
	}
	else {
		int num_str_index = 0;
		for (int i = digit_count; i > 0; i--) {
			int temp_num = char_count / power(10, i - 1);

			num_str[num_str_index] = temp_num + '0';
			num_str_index++;
			char_count = char_count % power(10, i - 1);
		}
	}

	shift_string_left(str, start_index + digit_count, end_index);

	for (int i = 1; i <= digit_count; i++) {
		str[start_index + i] = num_str[i - 1];
	}

	return start_index + digit_count + 1;
}
