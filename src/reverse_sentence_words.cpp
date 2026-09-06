#include <iostream>
#include <cstring>

using namespace std;

int string_length(char[]);
int find_last_space(char[], int);
void remove_spaces(char[], int);
int count_spaces(char[], int);
void shift_string_right(char[], int, int);
void shift_string_left(char[], int, int);

int main() {
	char str[] = "Hello            World   Foo Me    Hello   ";
	//int str_length = string_length(str);
	int str_length = 43;

	//remove_spaces(str, str_length);
	//str_length = string_length(str);
	
	if (str[str_length - 1] == 32) {
		str[str_length - 1] == '\0';
	}
	else {
		cout << "Hello";
	}

	str_length--;

	int last_space_index = find_last_space(str, str_length);
	int space_count = count_spaces(str, str_length);
	int skip_index = 0;

	cout << "Current String = (" << str << ")" << "\n\n";

	for (int x = 0; x < space_count; x++) {
		for (int i = last_space_index + 1; i < str_length; i++) {
			char first_char = str[i];

			shift_string_right(str, i, skip_index);
			str[skip_index] = first_char;
			skip_index++;

			cout << "String Now = (" << str << ")" << "\n";
		}

		shift_string_right(str, str_length - 1, skip_index);
		str[skip_index] = ' ';
		skip_index++;
		last_space_index = find_last_space(str, str_length);
	}

	cout << "\nFinal String = (" << str << ")";
}

int string_length(char str[]) {
	int count = 0;

	while (str[count] != '\0') {
		count++;
	}
		
	return count;
}

int find_last_space(char str[], int str_length) {
	int last_space_index = 0;

	for (int i = str_length; i > 0; i--) {
		if (str[i] == ' ') {
			last_space_index = i;
		}
	}

	return last_space_index;
}

void remove_spaces(char str[], int string_length) {
	int count = 0;

	for (int i = 0; i < string_length - count; i++) {
		if (str[i] == ' ' && str[i + 1] == ' ' && i < string_length - 1) {
			count++;

			shift_string_left(str, i, string_length + 1);
			i--;
		}
	}
}

int count_spaces(char str[], int str_length) {
	int sapce_count = 0;

	for (int i = 0; i < str_length; i++) {
		if (str[i] == ' ') {
			sapce_count++;
		}
	}

	return sapce_count;
}

void shift_string_right(char str[], int ending_index, int skip_index) {
	for (int i = ending_index; i > skip_index; i--) {
		str[i] = str[i - 1];

	}
}

void shift_string_left(char str[], int starting_index, int ending_index) {
	for (int i = starting_index; i < ending_index; i++) {
		str[i] = str[i + 1];
	}
}
