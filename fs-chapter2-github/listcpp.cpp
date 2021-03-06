// D.2 listcpp.cpp

// list contents of file using C++ stream classes
#include <fstream>
#include <iostream>
using namespace std;
/*
iostream.h
ostream& operator<<(char c);
istream& operator>>(char c);
*/
int main (void)
{
	char ch;
	fstream file; // declare fstream unattached
	char filename[20];
	cout <<"Enter the name of the file: "	// Step 1 -> test3.txt
		<<flush; // force output
	cin >> filename;						// Step 2 
	file . open(filename, ios::in);			// Step 3 
	file . unsetf (ios::skipws);// include white space in read. 
	while (1)	// It is open exist file and read context to cout
	{
		file >> ch;							// Step 4a 
		if (file.fail()) {
			break;
		}
		cout << ch;							// Step 4b 
	}
	file . close();							// Step 5
	system("pause");
	return 1;
}