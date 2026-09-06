#include <iostream>
#include <limits>

using namespace std;

struct Address { // (1 + 1 + 4 + 4) + 6 + 6
	char* city;
	char* street;
	int zip_code;
	static const int count = 0;
};

struct Person {
	char* name;
	int age;
	Address* address;
};

struct Department {
	char* name; // attribute (type, name)
	int no_of_persons; // attribute
	Person* persons; // attribute
};

void person_data_input(Person*, int, int);
void add_persons(Department&, int);
void search_and_print_person_by_city(Department, char[]);
void print_department_details(Department);

int main() {
	// predefined types, user defined types
	// int, float, char etc., Department, Person, Address
	// variable, object
	//int x = 10;
	//int z = 20;
	//cout << x + z;
	
	//Department y;
	//y.name = new char[100];
	//y.no_of_persons = 0;
	//y.persons = nullptr;

	//Department z;
	//z.name = new char[100];
	//z.no_of_persons = 0;
	//z.persons = nullptr;

	//char* arr = new char[100];
	//char* arr1 = arr;
	//char* arr2 = new char[100];
	//for (int i = 0; i < 100; i++) {
	//	arr2[i] = arr[i];
	//}


	Department department_1;

	cout << "Enter department name: ";
	department_1.name = new char[100];
	cin.getline(department_1.name, 100);

	cout << "Enter number of persons in department: ";
	cin >> department_1.no_of_persons;

	department_1.persons = new Person[department_1.no_of_persons];
	person_data_input(department_1.persons, 0, department_1.no_of_persons);
	
	//add more persons in department
	char choice;
	cout << endl << "Do you wnat to add more persons to department [y/n]: ";
	cin >> choice;

	if (choice == 'y' || choice == 'Y') {
		int persons_to_add;
		cout << " -> Emter number of persons to add: ";
		cin >> persons_to_add;

		add_persons(department_1, persons_to_add);
		person_data_input(department_1.persons, department_1.no_of_persons - persons_to_add, department_1.no_of_persons);
	}

	//search person by city
	char city_name[100];

	cout << endl << "Do you want to search person by city [y/n]: ";
	cin >> choice;

	if (choice == 'y' || choice == 'Y') {
		cout << "Enter city to search: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin.getline(city_name, 100);

		search_and_print_person_by_city(department_1, city_name);
	}

	//printing all department data
	print_department_details(department_1);

	//memory disallocation
	for (int i = 0; i < department_1.no_of_persons; i++) {
		delete[] department_1.persons[i].name;
		department_1.persons[i].name = nullptr;

		delete[] department_1.persons[i].address->city;
		department_1.persons[i].address->city = nullptr;
		delete[] department_1.persons[i].address->street;
		department_1.persons[i].address->street = nullptr;
		delete department_1.persons[i].address;
		department_1.persons[i].address = nullptr;
	}
	delete[] department_1.persons;
	department_1.persons = nullptr;
	delete[] department_1.name;
	department_1.name = nullptr;

	return 0;
}

void person_data_input(Person *persons, int starting_index, int no_of_persons) {
	for (int index = starting_index; index < no_of_persons; index++) {
		cout << endl << "Enter person name: ";
		persons[index].name = new char[100];
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin.getline(persons[index].name, 100);

		cout << "Enter person age: ";
		cin >> persons[index].age;

		persons[index].address = new Address;
		Address* address = persons[index].address;

		cout << "Enter city: ";
		address->city = new char[100];
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin.getline(address->city, 100);

		cout << "Enter street name: ";
		address->street = new char[100];
		cin.getline(address->street, 100);

		cout << "Enter ZIP cide: ";
		cin >> address->zip_code;
	}
}

void add_persons(Department& department, int persons_to_add) {
	//creating new Person array
	Person* const new_persons = new Person[department.no_of_persons + persons_to_add];
	//copying data to new array
	int index = 0;
	for (index; index < department.no_of_persons; index++) {
		new_persons[index].name = department.persons[index].name;
		new_persons[index].age = department.persons[index].age;
		new_persons[index].address = department.persons[index].address;
	}
	
	delete[] department.persons;

	department.persons = new_persons;
	department.no_of_persons += persons_to_add;
}

void search_and_print_person_by_city(Department department, char city_name[]) {
	int match_count = 0;

	for (int i = 0; i < department.no_of_persons; i++) {
		bool match_found = true;
		int index = 0;

		while (city_name[index] != '\0') {
			if (department.persons[i].address->city[index] != city_name[index]) {
				match_found = false;
				break;
			}
			index++;
		}

		if (match_found) {
			match_count++;
			cout << endl;
			cout << "1. Match Found!" << endl;
			cout << "  -> Person Name: " << department.persons[i].name << endl;
			cout << "  -> Age: " << department.persons[i].age << endl;
			cout << "  -> Addresss: -" << endl;
			cout << "    -> city: " << department.persons[i].address->city << endl;
			cout << "    -> street: " << department.persons[i].address->street << endl;
			cout << "    -> zip: " << department.persons[i].address->zip_code << endl;
		}
	}

	if (match_count == 0) {
		cout << endl << "No Match Found!" << endl;
	}
}

void print_department_details(Department department) {
	cout << endl;
	cout << "Department name : " << department.name << endl;
	cout << "No. of persoms: " << department.no_of_persons << endl << endl;
	for (int index = 0; index < department.no_of_persons; index++) {
		Person person = department.persons[index];
		
		cout << index + 1 << ". Person name: " << person.name << endl;
		cout << "  -> Age: " << person.age << endl;
		
		const Address* address = person.address;

		cout << "  -> Address: -" << endl;
		cout << "    -> City: " << address->city << endl;
		cout << "    -> Street: " << address->street << endl;
		cout << "    -> ZIP: " << address->zip_code << endl;
	}
}