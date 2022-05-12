// test.cc
// Copyright 1997, Gregory A. Riccardi

#include <fstream>
#include <iomanip>
#include "fixtext.h"
#include "lentext.h"
#include "deltext.h"
#include "Student.h"
using namespace std;

void testFixText ()
{
	int result;
	Student st;
	
	FixedTextBuffer Buff (6); //FixedTextBuffer (int maxFields, int maxChars = 1000);
	Student :: InitBuffer (Buff);
	strcpy (st.Name, "Darling");
	strcpy (st.Address, "4112 Center St.");
	strcpy (st.DateOfFirstEnrollment, "20180225");
	st.Identifier = 1;
	st.NumberOfCreditHourse = 23;
	st . Print (cout);

	st . Pack (Buff);
	Buff . Print (cout);
	ofstream TestOut ("fixtext.txt",ios::out);
	Buff . Write (TestOut);
	strcpy (st.Name, "Dave");
	st.Print (cout);

	st.Pack (Buff);
	Buff . Write (TestOut);
	TestOut . close ();
	ifstream TestIn ("fixtext.txt");
	FixedTextBuffer InBuff (6);
	Student :: InitBuffer (InBuff);
	Buff . Read (TestIn);
	st . Unpack (Buff);
	st . Print (cout);
}


//void testLenText ()
//{
//	cout << "\nTesting LengthTextBuffer"<<endl;
//	Student st;
//	LengthTextBuffer Buff;
//	Student :: InitBuffer (Buff);
//	strcpy (st.Name, "Darling");
//	strcpy (st.Address, "4112 Center St.");
//	strcpy (st.DateOfFirstEnrollment, "20220614");
//	st.Identifier = 1;
//	st.NumberOfCreditHourse = 23;
//	st . Print (cout);
//	Buff . Print (cout);
//	cout <<"pack person "<<st . Pack (Buff)<<endl;
//	Buff . Print (cout);
//	ofstream TestOut ("lentext.txt",ios::out);
//	Buff . Write (TestOut);
//	strcpy (st.Name, "Dave");
//	st.Print (cout);
//	st.Pack (Buff);
//	Buff . Write (TestOut);
//	TestOut . close ();
//	ifstream TestIn ("lentext.txt");
//	LengthTextBuffer InBuff;
//	Student:: InitBuffer (InBuff);
//	cout <<"read "<<Buff . Read (TestIn)<<endl;
//	cout <<"unpack "<<st . Unpack (Buff)<<endl;
//	st . Print (cout);
//	cout <<"read "<<Buff . Read (TestIn)<<endl;
//	cout <<"unpack "<<st . Unpack (Buff)<<endl;
//	st . Print (cout);
//	cout <<"read "<<Buff . Read (TestIn)<<endl;
//	cout <<"unpack "<<st . Unpack (Buff)<<endl;
//	st . Print (cout);
//}


//void testDelText ()
//{
//	cout << "\nTesting DelimTextBuffer"<<endl;
//	Student st;
//	DelimTextBuffer Buff;
//	Student::InitBuffer (Buff);
//	strcpy (st.Name, "Darling");
//	strcpy (st.Address, "4112 Center St.");
//	strcpy (st.DateOfFirstEnrollment , "20220614");
//	st.Identifier = 1;
//	st.NumberOfCreditHourse = 23;
//	st.Print (cout);
//	Buff . Print (cout);//start with an empty buffer object
//	cout <<"pack person "<< st.Pack (Buff)<<endl;//pack field values into the object
//	Buff . Print (cout);
//
//	ofstream TestOut ("deltextperson.txt",ios::out);
//	Buff . Write (TestOut);//write the buffer contents to an output stream
//	strcpy (st.Name, "Dave");
//	st.Print (cout);
//
//	st.Pack (Buff);
//	Buff . Write (TestOut);
//	TestOut . close ();
//	cout << "+++++++++++++++++++++++++++++" << endl;
//	ifstream TestIn ("deltextperson.txt");
//	DelimTextBuffer InBuff;
//	Student :: InitBuffer (InBuff);
//
//	cout <<"read "<<Buff . Read (TestIn)<<endl;
//	cout <<"unpack "<<st . Unpack (Buff)<<endl;
//	st. Print (cout);
//
//
//	cout <<"read "<<Buff . Read (TestIn)<<endl;
//	cout <<"unpack "<<st . Unpack (Buff)<<endl;
//	st . Print (cout);
//
//	cout <<"read "<<Buff . Read (TestIn)<<endl;
//	cout <<"unpack "<<st . Unpack (Buff)<<endl;
//	st . Print (cout);
//}
int main(void)
{
	//testDelText();
	testFixText ();
	//testLenText ();
	system("pause");
	return 1;
}
