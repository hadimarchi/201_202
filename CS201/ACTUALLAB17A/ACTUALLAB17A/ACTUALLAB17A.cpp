// Lab17A.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <iterator>
//#include <algorithm>
#include <fstream>
#include <ostream>
#include <vector>
#include <string>
using namespace std;
void printVec(const vector<char> & data)
{
	for (int i = 0; i<data.size(); ++i)
	{
		cout << data[i];
	}
	cout << endl;
}
int main()
{
	string fname = "bestsong.txt";
	string fname2;
	fstream fs(fname, ios::in);
	char * temp = new char;
	vector<char> aVec;
	if (!fs.good()) {
		cout << "This file is not readable, or cannot be found. Send help." << endl;
		system("PAUSE");
		return 1;
	}
	cout << fs.good() << endl;
	while (!fs.eof()) {
		fs.read(temp, sizeof(char));

		aVec.push_back(*temp);
	}

	cout << "Do you want to print the lyrics to the console or to a seperate file?" << endl;
	cout << "Type 1 to print to the console" << endl;
	cout << "And 2 to print to a seperate file." << endl;
	int a;
	cin >> a;
	switch (a) {
	case 1:

		printVec(aVec);
		system("PAUSE");
		break;
	case 2:
		cout << "What would you like the name of this file to be?" << endl;
		cin >> fname2;
		if (true) {
			ofstream fs2;
			fs2.open(fname2, ios::out);
			
			fs2.write((char*)&aVec[0], aVec.size());
			fs2.close();
		}

		break;
	default:	
		cout << "Pick an actual option next time" << endl;
	}

	delete temp;
	return 0;
}

