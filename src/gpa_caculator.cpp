#include <iostream>
#include <iomanip>

using namespace std;

float calc_subject_gp(float obtained, float total, float cred_hours) {
	float gp = 0, percentage = (obtained / total) * 100;
	
	if (percentage >= 85) {
		gp = 4;
	}
	else if (percentage >= 80) {
		gp = 3.66;
	}
	else if (percentage >= 75) {
		gp = 3.33;
	}
	else if (percentage >= 71) {
		gp = 3;
	}
	else if (percentage >= 68) {
		gp = 2.66;
	}
	else if (percentage >= 64) {
		gp = 2.33;
	}
	else if (percentage >= 61) {
		gp = 2;
	}
	else if (percentage >= 58) {
		gp = 1.66;
	}
	else if (percentage >= 54) {
		gp = 1.3;
	}
	else if (percentage >= 50) {
		gp = 1;
	}
	else {
		gp = 0;
	}

	return gp * cred_hours;
}

float calc_gpa(float gp_1, float gp_2, float gp_3, float gp_4, float gp_5, float cred_hours_1, float cred_hours_2, float cred_hours_3, float cred_hours_4, float cred_hours_5) {
	float total_gp = gp_1 + gp_2 + gp_3 + gp_4 + gp_5;
	float total_cred_hours = cred_hours_1 + cred_hours_2 + cred_hours_3 + cred_hours_4 + cred_hours_5;
	return total_gp / total_cred_hours;
}

void subject_status(float obtained, float total, int count) {
	cout << "Subject " << count << " Status: ";
	if (((obtained / total) * 100) >= 50) {
		cout << "Pass";
	}
	else {
		cout << "Fail";
	}

	count++;
}

void get_input(float& obtained, float& total, int& cred_hours, int& count) {
	bool safety_check = true;

	cout << "Enter subject " << count <<  " total marks: ";
	cin >> total;
	cout << "Enter subject " << count << " obtained marks : ";
	cin >> obtained;
	cout << "Enter subject " << count << " credit hours : ";
	cin >> cred_hours;
	cout << "\n";

	while (safety_check) {
		if (total <= 0) {
			cout << "Error: Invalid Input" << "\n" << "Re-enter subject " << count << " marks: ";
			cin >> total;
		}
		else if (obtained < 0) {
			cout << "Error: Invalid Input" << "\n" << "Re-enter subject " << count << " obtained marks : ";
			cin >> obtained;
		}
		else if (obtained > total) {
			cout << "Error: obtained marks should not be greater than total marks" << "\n"
				<< "Re-enter subject " << count << " obtained marks : ";
			cin >> obtained;
		}
		else if (cred_hours <= 0) {
			cout << "Error: Invalid Input" << "\n" << "Re-enter subject " << count << " credit hours : ";
			cin >> cred_hours;
		}
		else {
			safety_check = false;
		}
	}

	count++;
}

void print_result(float gpa, float obtained_1, float obtained_2, float obtained_3, float obtained_4, float obtained_5, float total_1, float total_2, float total_3, float total_4, float total_5) {
	int count = 1;

	cout << "Total GPA: " << setprecision(2) << gpa;
	if (gpa >= 2) {
		cout << "\nSemester Status: Passed";
	}
	else {
		cout << "\nSemester Status: Failed";
	}

	subject_status(obtained_1, total_1, count);
	subject_status(obtained_2, total_2, count);
	subject_status(obtained_3, total_3, count);
	subject_status(obtained_4, total_4, count);
	subject_status(obtained_5, total_5, count);
}
 
int main() {
	float total_1, total_2, total_3, total_4, total_5,
		obtained_1, obtained_2, obtained_3, obtained_4, obtained_5,
		gp_1, gp_2, gp_3, gp_4, gp_5, gpa;
	int cred_hours_1, cred_hours_2, cred_hours_3, cred_hours_4, cred_hours_5;
	char choice = 'y';

	while (choice == 'y' || choice == 'Y') {
		int count = 1;

		// step 1: taking input from user
		get_input(obtained_1, total_1, cred_hours_1, count);
		get_input(obtained_2, total_2, cred_hours_2, count);
		get_input(obtained_3, total_3, cred_hours_3, count);
		get_input(obtained_4, total_4, cred_hours_4, count);
		get_input(obtained_5, total_5, cred_hours_5, count);

		// step 2: calculate subject grade points
		gp_1 = calc_subject_gp(obtained_1, total_1, cred_hours_1);
		gp_2 = calc_subject_gp(obtained_2, total_2, cred_hours_2);
		gp_3 = calc_subject_gp(obtained_3, total_3, cred_hours_3);
		gp_4 = calc_subject_gp(obtained_4, total_4, cred_hours_4);
		gp_5 = calc_subject_gp(obtained_5, total_5, cred_hours_5);

		// step 3: calculate semester gpa 
		gpa = calc_gpa(gp_1, gp_2, gp_3, gp_4, gp_5, cred_hours_1, cred_hours_2, cred_hours_3, cred_hours_4, cred_hours_5);

		// step 3: printing result
		print_result(gpa, obtained_1, obtained_2, obtained_3, obtained_4, obtained_5, total_1, total_2, total_3, total_4, total_5);

		cout << "\n\nDo you want to resatrt program [y/n] : ";
		cin >> choice;
		system("cls");
	}

	return 0;
}
