#include <iostream>

using namespace std;

int string_len(char[]);
int sub_str(char[], char[]);

int main() {
	char str[] = "Banaanea";	
	char temp_str[] = "ea";
	int index = sub_str(str, temp_str);

	cout << "Main String: " << str << endl;
	cout << "Search String: " << temp_str << endl;

	if (index == -1) {
		cout << "No match found!" << endl;
	}
	else {
		cout << "Match Found at " << index << " index" << endl;
	}

	return 0;
}

int string_len(char str[]) {
	int length = 0;

	while (str[length] != '\0') {
		length++;
	}

	return length;
}

int sub_str(char str[], char sub_str[]) {
	int str_len = string_len(str);
	int sub_str_len = string_len(sub_str);
	int temp_count = 0;
	int starting_index = 0;
	bool is_found = false;
	

	for (int index = 0; index < str_len; index++) {
		char substr_lett = sub_str[temp_count];
		if (substr_lett == str[index]) {
			temp_count++;
		}
		else {
			temp_count = sub_str[0] == str[index];
			starting_index = index;
		}

		if (temp_count == sub_str_len) {
			is_found = true;
			break;
		}
	}

	return is_found ? starting_index : -1;
}