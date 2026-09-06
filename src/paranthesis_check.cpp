#include <iostream>

using namespace std;

char open_to_close_bracket(char);

int main() {
	char str[] = "{{[(])}}";
	char stack[100];
	int index = 0, stack_fill_index = 0;

	while (str[index] != '\0') {
		char bracket = str[index];

		if (bracket == '(' || bracket == '[' || bracket == '{') {
			//stack push
			stack[stack_fill_index++] = bracket;
		}
		else if (bracket == ')' || bracket == ']' || bracket == '}') {
			if (stack_fill_index == 0) {
				cout << "\nBrackets are not Valid!";
				return 0;
			}

			char popped_bracket = stack[stack_fill_index - 1];
			if ((popped_bracket == '(' && bracket == ')')
				|| (popped_bracket == '{' && bracket == '}')
				|| (popped_bracket == '[' && bracket == ']')) {
				stack_fill_index--;
			}
			else {
				cout << "\nBrackets are not Valid!";
				return 0;
			}
		}

		cout << "Stack at index " << index << " : ";
		for (int i = 0; i < stack_fill_index; i++) {
			cout << stack[i];
		}
		cout << endl;
		

		index++;
	}

	cout << "\nBrackets are Valid!";
	return 0;
}
