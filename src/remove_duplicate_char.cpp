#include <iostream>

using namespace std;

int main() {
	char str[] = "Progggggrammmmmmingggg";
	int hash_table[60][2]{};
	int index = 0, skip_index = 0;

	while (str[index] != '\0') {
		bool is_found = false;

		for (int i = 0; i < skip_index; i++) {
			if (str[index] == hash_table[i][0]) {
				is_found = true;
				hash_table[i][1]++;
			}
		}

		if (!is_found) {
			hash_table[skip_index][0] = int(str[index]);
			skip_index++;
		}

		index++;
	}

	for (index = 0; index < skip_index; index++) {
		cout << char(hash_table[index][0]);
	}
	
	return 0;
}