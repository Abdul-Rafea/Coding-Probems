#include <iostream>
#include <iomanip>

using namespace std;

struct Subject {
	int obtained_marks;
	int total_marks;
};

struct Student {
	char name[100]; // can be dynamic
	int roll_no;
	float percentage;
	static const int SUBJECT = 3; // will explain later
	Subject subjects[SUBJECT]; // dynamic is better
};

int no_of_digits(int);
void data_input(Student*, int);
void calc_percentage(Student*, int);
int string_length(char[]);
int largest_name_length(Student*, int);
void print_result(Student*, int);

int main() {
	int no_of_students;
	cout << "Enter number of students: ";
	cin >> no_of_students;
	cout << endl;

	Student* students = new Student[no_of_students];
	
	data_input(students, no_of_students);
	calc_percentage(students, no_of_students);
	print_result(students, no_of_students);

	delete students;

	return 0;
}

int no_of_digits(int num) {
	int digit_count = 0;

	while (num != 0) {
		num = num / 10;
		digit_count++;
	}

	return digit_count;
}

int string_length(char str[]) {
	int length = 0;

	while (str[length] != '\0') {
		length++;
	}

	return length;
}

void data_input(Student* students, int no_of_students) {
	for (int index = 0; index < no_of_students; index++) {
		cout << "Enter student name: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin.getline(students[index].name, 100);

		cout << "Enter 5 digit roll no: ";
		cin >> students[index].roll_no;

		//roll no check
		while (true) {
			int digits = no_of_digits(students[index].roll_no);
			
			if (digits != 5) {
				cout << "ERROR: Roll no should only be 5 digits!" << endl;
				cout << "Re-enter 5 digit roll no: ";
				cin >> (students[index]).roll_no;
			}
			else {
				break;
			}
		}
		
		for (int i = 0; i < students[index].SUBJECT; i++) {
			cout << "Enter subject " << i + 1 << " total marks: ";
			cin >> students[index].subjects[i].total_marks;

			cout << "Enter subject " << i + 1 << " obtained marks: ";
			cin >> students[index].subjects[i].obtained_marks;
			
			//marks check
			while (true) {
				int obtained_marks = students[index].subjects[i].obtained_marks;
				int total_marks = students[index].subjects[i].total_marks;
				
				if (obtained_marks > total_marks) {
					cout << "ERROR: obtained marks should be less that total marks" << endl;
					cout << "Re-enter subject " << i + 1 << " obtained marks: ";
					cin >> students[index].subjects[i].obtained_marks;
				}
				else {
					break;
				}
			}
		}
		cout << endl;
	}
}

void calc_percentage(Student* students, int no_of_students) {
	for (int index = 0; index < no_of_students; index++) {
		float obtained_marks = 0;
		float total_marks = 0;
		
		for (int i = 0; i < students[index].SUBJECT; i++) {
			obtained_marks += students[index].subjects[i].obtained_marks;
			total_marks += students[index].subjects[i].total_marks;
		}

		students[index].percentage = (obtained_marks / total_marks) * 100;
	}
}

int largest_name_length(Student* students, int no_of_students) {
	int largest_length = 0;

	for (int index = 0; index < no_of_students; index++) {
		int length = string_length(students[index].name);

		if (length > largest_length) {
			largest_length = length;
		}
	}
	
	return largest_length;
}

void print_result(Student* students, int no_of_students) {
	int name_col_length = largest_name_length(students, no_of_students);
	int row_length = (1 + name_col_length + 1) + (2 + 5 + 1) + (2 + 4 + 3);

	cout << endl << "Result: -" << endl;
	
	for (int i = 0; i < row_length; i++) {
		cout << "=";
	}
	cout << endl;
	for (int index = 0; index < no_of_students; index++) {
		int name_col_spaces = name_col_length - string_length(students[index].name);
		
		//printing student name
		cout << "| " << students[index].name;
		for (int x = 0; x < name_col_spaces; x++) {
			cout << " ";
		}
		cout << " ";

		//printing roll no
		cout << "| " << students[index].roll_no << " ";

		//printing percentage
		cout << "| " << setprecision(4) << students[index].percentage << " ";
		cout << "|";

		cout << endl;
	}

	for (int i = 0; i < row_length; i++) {
		cout << "=";
	}
}
