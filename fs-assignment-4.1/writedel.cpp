// writedel.cpp => readdel.cpp
// write a stream of persons, using fstream.h 
/*
istream::getline
istream& getline(char*s, streamsize n);//�Է� stream ���� ���� ���ڸ� �о�鿩 s�� �����Ѵ�. delimiter�� '\n'�� ����Ѵ�.
istream& getline(char*s, streamsize n, char delim);//delimiter�� ��Ÿ�� ������ �а� �ȴ�. delimiter�� delim ���� ���޵ȴ�.
*/
#include <iostream>
#include <fstream>
#include "student.h"
using namespace std;
// Figure 4.1 => 2�� �ҽ��ڵ�� �ǽ�
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
