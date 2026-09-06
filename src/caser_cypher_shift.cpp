#include <iostream>

using namespace std;

int string_length(char[]);
char casear_shift(char);

int main() {
	char str[] = "VSZZC";
	int str_len = string_length(str);

	for (int i = 0; i < 26; i++) {
		cout << "Shift " << i << " : ";
		for(int index = 0; index < str_len; index++) {
			char shift = casear_shift(str[index]);
			str[index] = shift;
			cout << shift;
		}
		cout << endl;
	}

	return 0;
}

int string_length(char str[]) {
	int length = 0;
	while (str[length] != '\0') {
		length++;
	}

	return length;
}

char casear_shift(char x) {
	int ascii = int(x);
	if (ascii == 65) {
		ascii = 90;
	}
	else {
		ascii--;
	}

	return char(ascii);
}