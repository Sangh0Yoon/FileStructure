#include <iostream>
#include <string>
#include <algorithm>
#include "student.h"

Student::Student()
{//constructor
	Identifier = 0; Name[0] = 0; Address[0] = 0;
	DateOfFirstEnrollment[0] = 0; NumberOfCreditHourse = 0;
}

Student::Student(int id, int number, char* name, char* addr, char* date) {
	strcpy(Name, name);
	strcpy(Address, addr);
	strcpy(DateOfFirstEnrollment, date);
	Identifier = id;
	NumberOfCreditHourse = number;
}

void Student::increase_creditHours(int n) {
	NumberOfCreditHourse += n;
}

Student& Student::operator=(Student& st) {
	Identifier = st.Identifier;
	NumberOfCreditHourse = st.NumberOfCreditHourse;
	strcpy(Name, st.Name);
	strcpy(Address, st.Address);
	strcpy(DateOfFirstEnrollment, st.DateOfFirstEnrollment);
	return *this;
}

istream& operator>>(istream& stream, Student& s) {
	int n;
	cout << "Enter Name : "; stream.getline(s.Name, 11);
	cout << "Enter Address : "; stream.getline(s.Address, 16);
	cout << "Enter Date Of First Enrollment : "; stream.getline(s.DateOfFirstEnrollment, 16);
	cout << "Enter Identifier : "; stream >> n; s.Identifier = n; stream.ignore();
	cout << "Enter Number of Credit Hourse : "; stream >> n; s.NumberOfCreditHourse = n; stream.ignore();
	return stream;
}
ostream& operator<<(ostream& stream, Student& s) {
	stream << "Name '" << s.Name << "'\n"
		<< "\tAddress '" << s.Address << "'\n"
		<< "\tDate Of First Enrollment '" << s.DateOfFirstEnrollment << "'\n"
		<< "\tIdentifier '" << s.Identifier << "'\n"
		<< "\tNumber Of Credit Hourse '" << s.NumberOfCreditHourse << "'\n" << std::flush;
	return stream;
}