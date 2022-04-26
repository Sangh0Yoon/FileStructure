// create a list of student information
#include "Student.h"
#include <iostream>
using namespace std;
int main() {
	Student st1(1,23,"Yoon", "Busan", "20220426");
	Student st2;

	cout << endl << "st2 = st1 is called" << endl;
	st2 = st1;

	Student st3 = st2;
	cout << endl << "st3 = st4 is called::" << endl;
	Student st4(2, 20, "Park", "Ulsan", "20220422");
	st3 = st4;

	cout << endl << "st1 print";
	cout << st1 << endl;
	cout << endl << "st2 print";
	cout << st2 << endl;
	cout << endl << "st3 print";
	cout << st3 << endl;
	system("pause");
	return 1;
}
