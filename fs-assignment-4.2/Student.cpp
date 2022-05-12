#include <iostream>
#include <string>
#include <algorithm>
#include "Student.h"
using namespace std;

Student::Student(){
	Clear();
}
Student::Student(int id, int number, char* name, char* addr, char* date) {
	strcpy(Name, name);
	strcpy(Address, addr);
	strcpy(DateOfFirstEnrollment, date);
	Identifier = id;
	NumberOfCreditHourse = number;
}
void Student::Clear() {
	Identifier = 0; Name[0] = 0; Address[0] = 0;
	DateOfFirstEnrollment[0] = 0; NumberOfCreditHourse = 0;
}
int Student::Pack(DelimTextBuffer& Buffer) const {
	int result;
	Buffer.Clear();
	result = Buffer.Pack(Name);
	result = result && Buffer.Pack(Address);
	result = result && Buffer.Pack(DateOfFirstEnrollment);
	string tmp = ""; tmp = to_string(Identifier); result = result && Buffer.Pack(tmp.c_str());
	tmp = ""; tmp = to_string(NumberOfCreditHourse); result = result && Buffer.Pack(tmp.c_str());
	return result;
}
int Student::Unpack(DelimTextBuffer& Buffer) {
	int result;
	result = Buffer.Unpack(Name);
	result = result && Buffer.Unpack(Address);
	result = result && Buffer.Unpack(DateOfFirstEnrollment);
	result = result && Buffer.Unpack(Identifier);
	result = result && Buffer.Unpack(NumberOfCreditHourse);
	return result;
}
int Student::InitBuffer(DelimTextBuffer& Buffer)
// initialize a DelimTextBuffer to be used for Persons
{
	return TRUE;
}


int Student::Pack(LengthTextBuffer& Buffer) const {
	int result;
	Buffer.Clear();
	result = Buffer.Pack(Name);
	result = result && Buffer.Pack(Address);
	result = result && Buffer.Pack(DateOfFirstEnrollment);
	string tmp = ""; tmp = to_string(Identifier); result = result && Buffer.Pack(tmp.c_str());
	tmp = ""; tmp = to_string(NumberOfCreditHourse); result = result && Buffer.Pack(tmp.c_str());
	return result;
}
int Student::Unpack(LengthTextBuffer& Buffer) {
	int result;
	result = Buffer.Unpack(Name);
	result = result && Buffer.Unpack(Address);
	result = result && Buffer.Unpack(DateOfFirstEnrollment);
	result = result && Buffer.Unpack(Identifier);
	result = result && Buffer.Unpack(NumberOfCreditHourse);
	return result;
}
int Student::InitBuffer(LengthTextBuffer& Buffer)
// initialize a LengthTextBuffer to be used for Persons
{
	return TRUE;
}


int Student::Pack(FixedTextBuffer& Buffer) const {
	int result;
	Buffer.Clear();
	result = Buffer.Pack(Name);
	result = result && Buffer.Pack(Address);
	result = result && Buffer.Pack(DateOfFirstEnrollment);
	string tmp = ""; tmp = to_string(Identifier); result = result && Buffer.Pack(tmp.c_str());
	tmp = ""; tmp = to_string(NumberOfCreditHourse); result = result && Buffer.Pack(tmp.c_str());
	return result;
}
int Student::Unpack(FixedTextBuffer& Buffer) {
	int result;
	result = Buffer.Unpack(Name);
	result = result && Buffer.Unpack(Address);
	result = result && Buffer.Unpack(DateOfFirstEnrollment);
	result = result && Buffer.Unpack(Identifier);
	result = result && Buffer.Unpack(NumberOfCreditHourse);
	return result;
}
int Student::InitBuffer(FixedTextBuffer& Buffer)
// initialize a LengthTextBuffer to be used for Persons
{
	int result;
	result = Buffer.AddField(10);
	result = result && Buffer.AddField(15);
	result = result && Buffer.AddField(15);
	result = result && Buffer.AddField(15);
	result = result && Buffer.AddField(15);
	return result;
}

void Student::Print(std::ostream& stream)
{
	stream << "Student:"
		<< "Name '" << Name << "'\n"
		<< "\tAddress '" << Address << "'\n"
		<< "\tDate Of First Enrollment '" << DateOfFirstEnrollment << "'\n"
		<< "\tIdentifier '" << Identifier << "'\n"
		<< "\tNumber Of Credit Hourse '" << NumberOfCreditHourse << "'\n" << std::flush;
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
