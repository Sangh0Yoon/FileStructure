// D.6 readvar.cpp
// write a stream of persons, using fstream.h 
#include <iostream>
#include <fstream>
#include <strstream>
#include <string.h>
#include <string>
#include "Student.h"
using namespace std;
istream & operator >> (istream & stream, Student& st)
{ // read fields from stream
	char delim;
	int n;
	stream.getline(st.Name, 30,'|');
	if (strlen(st.Name)==0) return stream; 
	stream.getline(st.Address,30,'|');
	stream.getline(st.DateOfFirstEnrollment,30,'|');
	stream >> n; st.Identifier = n; stream.ignore();
	stream >> n; st.NumberOfCreditHourse = n; stream.ignore();
	return stream;
}

//Fig 4.9 - read a variable-sized Person record
int ReadVariablePerson (istream & stream, Student& st)
{ // read a variable sized record from stream and store it in p
  // if read fails, set p.LastName to empty string and return 0
	short length;
	//istream& read(const char*, streamsize);
	stream . read ((char*)&length, sizeof(length)); //stream.read(&length, sizeof(length)) => 오류
	cout << "length = " << length << endl;
	if (stream . fail()){st.Name[0]=0; return 0;}
	char * buffer = new char[length+1];
	stream . read (buffer, length);
	buffer [length] = 0; // terminate buffer with null
	istrstream strbuff (buffer);
	strbuff >> st;
	return 1;
}
ostream& operator << (ostream& stream, Student& st)
{ // insert fields into file
	cout << "Student 객체를 출력한다" << endl;
	stream << st.Name << '|' << st.Address << '|'
		<< st.DateOfFirstEnrollment << '|' << st.Identifier << '|' << st.NumberOfCreditHourse << '|' << flush;
	cout << endl << flush;
	return stream;
}
int main (void){
	char filename [20];
	Student st;
	cout << "Enter the file name:"<<flush;
	cin.getline(filename, 19);
	ifstream stream (filename, ios::in);
	if (stream.fail()) {
		cout << "File open failed!" <<endl;
		return 0;
	}
	while (1) {
		// read fields of person
		ReadVariablePerson (stream, st);
		if (strlen(st.Name)==0) break;
		// write person to file
		cout << st;
	}
	system("pause");
	return 1;
}
