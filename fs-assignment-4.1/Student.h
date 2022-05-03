#pragma once
#ifndef STUDENT
#define STUDENT
#include <iostream>
using namespace std;

class Student
{
public:
	// data members
	int Identifier; char Name[11]; char Address[16];
	char DateOfFirstEnrollment[16]; int NumberOfCreditHourse;
	// method
	Student(); // default constructor
	Student(int id, int number, char* name, char* addr, char* date);
	void increase_creditHours(int n);
	Student& operator=(Student& st);
	friend istream& operator>>(istream& stream, Student& s);
	friend ostream& operator<<(ostream& stream, Student& s);
};

#endif