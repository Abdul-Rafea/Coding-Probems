#include <iostream>

using namespace std;

int string_length(char[]);
bool lowercase_check(char);
char lower_to_upper(char);
void print_array(char[], const int);

int main() {
	char str_1[] = "hello  ";
	char str_2[] = "ll  ";
	const int str_1_length = string_length(str_1);
	const int str_2_length = string_length(str_2);

	print_array(str_1, str_1_length);
	print_array(str_2, str_2_length);
	cout << str_1_length << " " << str_2_length << endl;

	int hash_table[58] = {};

	//filling hash table with str_1
	for (int index = 0; index < str_1_length; index++) {
		bool is_lowercase = lowercase_check(str_1[index]);
		if (is_lowercase) {
			str_1[index] = lower_to_upper(str_1[index]);
		}
		
		int ascii = int(str_1[index]);
		int hash_index = ascii - 32;

		hash_table[hash_index]++;
	}

	for (int i = 0; i < 58; i++) {
		cout << hash_table[i] << " ";
	}
	cout << endl;

	//finding if str_2 is a anagram
	for (int index = 0; index < str_2_length; index++) {
		bool is_lowercase = lowercase_check(str_2[index]);
		if (is_lowercase) {
			str_2[index] = lower_to_upper(str_2[index]);
		}

		int ascii = int(str_2[index]);
		int hash_index = ascii - 32;

		if (hash_table[hash_index] != 0) {
			hash_table[hash_index]--;
		}
		else {
			cout << "It is not an anagram." << endl;
			return 0;
		}
	}

	cout << "It is an anagram." << endl;

	return 0;
}

int string_length(char str[]) {
	int index = 0;

	while (str[index] != '\0') {
		index++;
	}
	return index;
}

bool lowercase_check(char x) {
	return x >= 97 && x <= 122;
}

char lower_to_upper(char x) {
	int lowercase = int(x);
	char uppercase = char(lowercase - 32);

	return uppercase;
}

void print_array(char arr[], int array_size) {
	cout << "[";
	for (int i = 0; i < array_size; i++) {
		cout << arr[i];
	}
	cout << "]";
	cout << endl;
}
