// D.7 writestr.cpp - 가변길이 레코드 + 가변길이 필드
// write a stream of persons, using fstream.h 
#include <iostream>
#include <fstream>
#include <string.h>
#include <string>
#include "Student.h"
using namespace std;

//Fig 4.7 write a variable-length, delimited buffer to a file
const int MaxBufferSize = 200;
int WritePerson (ostream & stream, Student & st)
{	char buffer [MaxBufferSize];
	strcpy(buffer, st.Name); strcat(buffer,"|");
	strcat(buffer, st.Address);  strcat(buffer,"|");
	strcat(buffer, st.DateOfFirstEnrollment);  strcat(buffer,"|");
	string tmp = to_string(st.Identifier);
	strcat(buffer, tmp.c_str()); strcat(buffer, "|");
	tmp = to_string(st.NumberOfCreditHourse);
	strcat(buffer, tmp.c_str());  strcat(buffer,"|");
	short length=strlen(buffer); 
	stream.write ((char *)&length, sizeof(length)); // write length
	stream.write (&buffer[0], length);
	return 1;
}
istream& operator >> (istream& stream, Student& st)
{ // read fields from input
	int n;
	cout << "Enter Name, or <cr> to end: " << flush;
	stream.getline(st.Name, 30);
	if (strlen(st.Name) == 0) return stream;
	cout << "Enter Address : " << flush; stream.getline(st.Address, 30);
	cout << "Enter Date Of First Enrollment : " << flush; stream.getline(st.DateOfFirstEnrollment, 30);
	cout << "Enter id : " << flush; stream >> n; st.Identifier = n; stream.ignore();
	cout << "Enter Number of Credit Hours : " << flush; stream >> n; st.NumberOfCreditHourse = n; stream.ignore();
	return stream;
}
int main (void){
	char filename [20];
	Student st;
	cout << "Enter the file name:"<<flush;
	cin.getline(filename, 19);
	ofstream stream (filename, ios::out);
	if (stream.fail()) {
		cout << "File open failed!" <<endl;
		return 0;
	}
	while (1) {
		// read fields of person
		cin >> st;
		if (strlen(st.Name)==0) break;
		// write person to output stream
		WritePerson(stream,st);
	}
	system("pause");
	return 1;
}

