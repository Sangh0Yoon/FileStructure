#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void readper(ifstream& in) {
	char buf[100];
	if (!in.is_open())
		cout << "파일을 찾을 수 없습니다." << "\n";
	while (in) {
		in.getline(buf, 100,'|');
		cout << buf << endl;
	}
}

int main() {
	char filename[20];
	cout << "Enter the file name:" << flush; //test2.txt
	cin.getline(filename, 19);
	ifstream in(filename, ios::in);
	readper(in);
	system("pause");
}