#include <fstream>
#include <iostream>
using namespace std;
int main (void)
{
	char ch;
	fstream file; // declare fstream unattached
	char filename[20];
	cout <<"Enter the name of the file: "	// Step 1 -> test1.txt
		<<flush; // force output
	cin >> filename;						// Step 2 
	file . open(filename, ios::in);			// Step 3 
	while (1)
	{
		file >> ch;							// Step 4a 
		if (file.fail()) break;
		cout << ch;							// Step 4b 
	}
	file . close();							// Step 5
	system("pause");
	return 1;
}