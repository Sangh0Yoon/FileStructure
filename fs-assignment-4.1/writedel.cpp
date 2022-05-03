// writedel.cpp => readdel.cpp
// write a stream of persons, using fstream.h 
/*
istream::getline
istream& getline(char*s, streamsize n);//입력 stream 으로 부터 문자를 읽어들여 s에 저장한다. delimiter를 '\n'를 사용한다.
istream& getline(char*s, streamsize n, char delim);//delimiter가 나타날 때까지 읽게 된다. delimiter는 delim 으로 전달된다.
*/
#include <iostream>
#include <fstream>
#include "student.h"
using namespace std;
// Figure 4.1 => 2장 소스코드로 실습
ostream & operator << (ostream & stream, Student& st)
{ // insert fields into file
	stream << st.Name << '|' << st.Address << '|'
		<< st.DateOfFirstEnrollment << '|' << st.Identifier << '|'
		<< st.NumberOfCreditHourse << '|';
	return stream;
}
istream& operator >> (istream& stream, Student& st)
{ // read fields from input
	cout << "Enter Name, or <cr> to end: " << flush;
	stream.getline(st.Name, 30);
	if (strlen(st.Name) == 0) return stream;
	cout << "Enter Address: " << flush; stream.getline(st.Address, 30);
	cout << "Enter Date Of First Enrollment: " << flush; stream.getline(st.DateOfFirstEnrollment, 30);
	int n;
	cout << "Enter Identifier: " << flush; stream >> n; st.Identifier = n; stream.ignore();
	cout << "Enter Number Of Credit Hours: " << flush; stream >> n; st.NumberOfCreditHourse = n; stream.ignore();
	return stream;
}
int main (void){
	char filename [20];
	Student st;
	cout << "Enter the file name:"<<flush;
	cin.getline(filename, 19);
	ofstream file (filename, ios::out);
	if (file.fail()) {
		cout << "File open failed!" <<endl;
		return 0;
	}
	while (1) {
		// read fields of person
		cin >> st;
		if (strlen(st.Name)==0) break;
		// write person to file
		file << st;
	}
	system("pause");
	return 1;
}
