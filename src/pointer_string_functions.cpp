#include <iostream>

using namespace std;

int str_len(char*);
void str_cat(char*, char*, int&, int);

int main() {
	char str_1[100] = "Mirza";
	int str_1_size = str_len(str_1);
	char str_2[] = " Abdul Rafea";
	int str_2_size = str_len(str_2);

	cout << "String 1: (" << str_1 << ")" << endl;
	cout << "  -> size: " << str_1_size << endl;

	cout << "String 2: (" << str_2 << ")" << endl;
	cout << "  -> size: " << str_2_size << endl << endl;

	str_cat(str_1, str_2, str_1_size, str_2_size);
	cout << "After concatenation:" << endl;
	cout << "  -> String 1: " << str_1 << endl;
	cout << "    -> size: " << str_1_size << endl;

	return 0;
}

int str_len(char* str) {
	int size = 0;

	while (*(str + size) != '\0') {
		size++;
	}

	return size;
}

void str_cat(char* str_1, char* str_2, int& str_1_len, int str_2_len) {
	int j;

	for (str_1_len, j = 0; j < str_2_len; str_1_len++, j++) {
		*(str_1 + str_1_len) = *(str_2 + j);
	}

	*(str_1 + str_1_len) = '\0';
}
