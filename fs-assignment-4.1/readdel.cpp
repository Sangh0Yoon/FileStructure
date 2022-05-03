// D.5 readdel.cpp => writedel.cpp
// read a stream of persons with delimited fields
#include <iostream>
#include <fstream>
#include <string.h>
#include "Student.h"
using namespace std;
//Fig 4.4 extraction operator from stream file for reading delimited fields into a person object
istream & operator >> (istream & stream, Student& st)
{ // read fields from file
	char delim;
	stream.getline(st.Name, 30,'|');
	if (strlen(st.Name)==0) return stream; 
	stream.getline(st.Address,30,'|');
	stream.getline(st.DateOfFirstEnrollment,30,'|');
	int n;
	stream >> n; st.Identifier = n; stream.ignore();
	stream >> n; st.NumberOfCreditHourse = n; stream.ignore();
	cout << endl << "istream.getline(object, size, '|') ½ÇÇàµÊ" << endl;
	return stream;
}
ostream& operator << (ostream& stream, Student& st)
{ // insert fields into file
	cout << "Person °´Ã¼¸¦ Ãâ·ÂÇÑ´Ù" << endl;
	stream << st.Name << '|' << st.Address << '|'
		<< st.DateOfFirstEnrollment << '|' << st.Identifier << '|'
		<< st.NumberOfCreditHourse << '|';
	cout << endl;
	return stream;
}
int main (void){
	char filename [20];
	Student st;
	cout << "Enter the file name:"<<flush;
	cin.getline(filename, 19);
	ifstream file (filename, ios::in);
	if (file.fail()) {
		cout << "File open failed!" <<endl;
		return 0;
	}
	while (1) {
		// read fields of person
		file >> st;
		if (strlen(st.Name)==0) break;
		// write person to file
		cout << st;
	}
	system("pause");
	return 1;
}
