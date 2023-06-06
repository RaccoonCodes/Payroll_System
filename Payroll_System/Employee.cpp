#include <iostream>
#include <string>
#include "Employee.h"

using namespace std;

Employee::Employee(const string& inName, const string& inLast, const int& inAge, const int& id) {
	setName(inName);
	setLastName(inLast);
	setAge(inAge);
	setId(id);
	printE();
}

void Employee::setName(const string& n) {
	name = n;
}
void Employee::setLastName(const string& ln) {
	lastName = ln;
}
void Employee::setAge(const int& a) {
	age = a;
}
void Employee::setId(const int& i) {
	id = i;
}

string Employee::getName() {
	return name;
}
string Employee::getLastName() {
	return lastName;
}
int Employee::getAge() {
	return age;
}
int Employee::getId() {
	return id;
}
void Employee::printE() {

	cout << "First name: " << getName() << endl;
	cout << "Last name: " << getLastName() << endl;
	cout << "Age: " << getAge() << endl;
	cout << "id: " << getId() << endl;
}