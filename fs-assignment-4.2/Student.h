#ifndef STUDENT
#define STUDENT
#include "fixtext.h"
#include "lentext.h"
#include "deltext.h"
using namespace std;

class Student {
public:
	int Identifier; char Name[11]; char Address[16];
	char DateOfFirstEnrollment[16]; int NumberOfCreditHourse;
	Student();
	Student(int id, int number, char* name, char* addr, char* date);
	void increase_creditHours(int n);
	Student& operator=(Student& st);
	friend istream& operator>>(istream& stream, Student& s);
	friend ostream& operator<<(ostream& stream, Student& s);
	void Clear();
	static int InitBuffer(FixedTextBuffer&);
	int Unpack(FixedTextBuffer&);
	int Pack(FixedTextBuffer&) const;
	static int InitBuffer(LengthTextBuffer&);
	int Unpack(LengthTextBuffer&);
	int Pack(LengthTextBuffer&) const;
	static int InitBuffer(DelimTextBuffer&);
	int Unpack(DelimTextBuffer&);
	int Pack(DelimTextBuffer&) const;
	void Print(std::ostream&);
	
};
#endif