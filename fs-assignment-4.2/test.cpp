// test.cc// Copyright 1997, Gregory A. Riccardi
// 4장 과제2: while(1) { } 문을 완성한다.
#include <iostream>
#include <fstream>
#include <string.h>
#include <iomanip>
#include <vector>
#include "fixtext.h"
#include "lentext.h"
#include "deltext.h"
#include "Student.h"
using namespace std;

int testFixText()
{
	int count = 0, select = 0;
	char filename[20];
	Student st;
	Student* stable[10];

	FixedTextBuffer InBuff(100);
	Student::InitBuffer(InBuff);

	cout << "Enter the file name:" << flush;
	cin.getline(filename, 19);
	cin.clear();

	while (1)
	{
		cout << "\nSelect command 1: record input, 2. display, 3. write to file, 4. read from file, 5: Quit => ";
		cin >> select;
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		switch (select) {
		case 1:
			//to store a array of Person objects by inputing
			cout << "the number of Person object records : ";
			cin >> count;
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			for (int i = 0; i < count; i++)
			{
				cin >> st;
				stable[i] = new Student(st);
			}
			break;
		case 2:
			// to display the array of Person objects into screen
			for (int i = 0; i < count; i++)
			{
				cout << *stable[i] << endl;
			}
			break;
		case 3:
		{
			// to write the array of Person objects into a file
			ofstream fostream(filename, ios::out | ios::in);
			if (fostream.fail()) {
				cout << "File open failed!" << endl;
				return 0;
			}
			Student::InitBuffer(InBuff);
			for (int i = 0; i < count; i++) {
				st = *stable[i];
				st.Pack(InBuff);
				InBuff.Write(fostream);
				InBuff.Clear();
				cout << "finish the write." << endl;
			}
			fostream.close();
			break;
		}
		case 4:
		{
			// to read the array of Person records from the file
			ifstream fistream(filename, ios::in | ios::binary);
			if (fistream.fail()) {
				cout << "File open failed!" << endl;
				return 0;
			}
			Student::InitBuffer(InBuff);
			for (int i = 0; i < count; i++) {
				InBuff.Read(fistream);
				st.Unpack(InBuff);
				cout << st << endl;
				InBuff.Clear();
			}
			fistream.close();
			break;
		}
		default:
			// others
			exit(0);
			break;
		}
	}
	return 1;
}

int testLenText()
{
	int count = 0, select = 0;
	char filename[20];
	Student st;
	Student* stable[10];
	LengthTextBuffer InBuff;
	Student::InitBuffer(InBuff);

	cout << "Enter the file name:" << flush;
	cin.getline(filename, 19);
	cin.clear();

	while (1) {
		cout << "\nSelect command 1: record input, 2. display, 3. write to file, 4. read from file, 5: Quit => ";
		cin >> select;
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		switch (select) {
		case 1:
			//to store a array of Person objects by inputing
			cout << "the number of Person object records : ";
			cin >> count;
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			for (int i = 0; i < count; i++) {
				cin >> st;
				stable[i] = new Student(st);
			}
			break;
		case 2:
			// to display the array of Person objects into screen
			for (int i = 0; i < count; i++) {
				cout << *stable[i] << endl;
			}
			break;
		case 3:
		{
			// to write the array of Person objects into a file
			ofstream fostream(filename, ios::out | ios::in);
			if (fostream.fail()) {
				cout << "File open failed!" << endl;
				system("pause");
				return 0;
			}
			Student::InitBuffer(InBuff);
			for (int i = 0; i < count; i++) {
				st = *stable[i];
				st.Pack(InBuff);
				InBuff.Write(fostream);
				InBuff.Clear();
				cout << "finish the write." << endl;
			}
			fostream.close();
			break;
		}
		case 4:
		{
			// to read the array of Person records from the file
			ifstream fistream(filename, ios::in | ios::binary);
			if (fistream.fail()) {
				cout << "File open failed!" << endl;
				return 0;
			}
			Student::InitBuffer(InBuff);
			for (int i = 0; i < count; i++) {
				InBuff.Read(fistream);
				st.Unpack(InBuff);
				cout << st << endl;
				InBuff.Clear();
			}
			fistream.close();
			break;
		}
		default: {
			// others
			exit(0);
			break;
		}
		}
	}
	return 1;

}

int testDelText()
{
	int count = 0, select = 0;
	char filename[20];
	Student st;
	Student* stable[10];
	DelimTextBuffer InBuff;
	Student::InitBuffer(InBuff);

	cout << "Enter the file name:" << flush;
	cin.getline(filename, 19);
	cin.clear();

	while(1){
		cout << "\nSelect command 1: record input, 2. display, 3. write to file, 4. read from file, 5: Quit => ";
		cin >> select;
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		switch (select) {
		case 1:
			//to store a array of Person objects by inputing
			cout << "the number of Person object records : ";
			cin >> count;
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			for (int i = 0; i < count; i++){
				cin >> st;
				stable[i] = new Student(st);
			}
			break;
		case 2:
			// to display the array of Person objects into screen
			for (int i = 0; i < count; i++) {
				cout << *stable[i] << endl;
			}
			break;
		case 3:
		{
			// to write the array of Person objects into a file
			ofstream fostream(filename, ios::out | ios::in);
			if (fostream.fail()) {
				cout << "File open failed!" << endl;
				system("pause");
				return 0;
			}
			Student::InitBuffer(InBuff);
			for (int i = 0; i < count; i++){
				st = *stable[i];
				st.Pack(InBuff);
				InBuff.Write(fostream);
				InBuff.Clear();
				cout << "finish the write." << endl;
			}
			fostream.close();
			break;
		}
		case 4:
		{
			// to read the array of Person records from the file
			ifstream fistream(filename, ios::in | ios::binary);
			if (fistream.fail()) {
				cout << "File open failed!" << endl;
				return 0;
			}
			Student::InitBuffer(InBuff);
			for (int i = 0; i < count; i++){
				InBuff.Read(fistream);
				st.Unpack(InBuff);
				cout << st << endl;
				InBuff.Clear();
			}
			fistream.close();
			break;
		}
		default: {
			// others
			exit(0);
			break;
		}
		}
	}
	return 1;
	
}

int main(void)
{
	cout << "\nTesting Buffer" << endl;
	int sel;
	cout << "\nSelect buffer type 1: Fixed Field Buffer, 2. Length Field Buffer, 3. Delim Field Buffer, 4. Quit => ";
	cin >> sel;
	cin.clear();
	cin.ignore(INT_MAX, '\n');
	switch (sel) {
	case 1:
		cout << "Testing Fixed Field Buffer" << endl;
		if (testFixText() == 0) cout << "***" << endl;
		break;
	case 2:
		cout << "\nTesting LengthTextBuffer" << endl;
		testLenText();
		break;
	case 3:
		cout << "\nTesting DelimTextBuffer" << endl;
		testDelText();
		break;
	default:
		break;
	}
	return 1;
}
