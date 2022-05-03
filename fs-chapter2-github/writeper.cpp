// D.7 writeper.cpp
// write a stream of persons, using fstream.h 
//Assignment to students - writestr.cpp를 참조하여 수정하여 완성: 실습
#include <iostream>
#include <fstream>
#include <string.h>
#include "person.h"
const int MaxBufferSize = 200;

int WritePerson (ostream & stream, Person & p)
{	char buffer [MaxBufferSize];
	strcpy(buffer, p.LastName); strcat(buffer,"|");
	strcat(buffer, p.FirstName); strcat(buffer,"|");
	strcat(buffer, p.Address);  strcat(buffer,"|");
	strcat(buffer, p.City);  strcat(buffer,"|");
	strcat(buffer, p.State);  strcat(buffer,"|");
	strcat(buffer, p.ZipCode);  strcat(buffer,"|");
	short length=strlen(buffer); 
	std::cout << length << std::flush;
	stream.write ((char *)&length, sizeof(length)); //숫자가 써져서 텍스트가 깨짐.
	stream.write ((char *)&buffer, length);
	return 0;
}

int main (){
	char filename [20];
	Person p;
	cout << "Enter the file name:"<<flush; // test2.txt
	cin.getline(filename, 19);
	ofstream stream (filename, ios::out);
	if (stream.fail()) {
		cout << "File open failed!" <<endl;
		return 0;
	}
	while (1) {
		// read fields of person
		cin >> p;
		if (strlen(p.LastName)==0) break;
		// write person to output stream
		WritePerson(stream,p);
	}
}

