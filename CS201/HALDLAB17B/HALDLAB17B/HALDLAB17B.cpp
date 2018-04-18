// HALDLAB17B.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <ostream>

using namespace std;

int main()
{
	int SIZE;
	cout << "How many numbers do you want to be in this file?" << endl;
	cin >> SIZE;
	char * temp = new char[SIZE];
	vector<char> aVec;
	ofstream fs;
	fs.open("randnum.txt", ios::out,ios::binary);
	int M = 48;
	int N = 57;
	for (int i = 0; i < SIZE; i++) {
		temp[i] = M + rand() / (RAND_MAX / (N - M + 1) + 1);
		aVec.push_back(temp[i]);
	}
	system("PAUSE");
	fs.write((char*)&aVec[0], SIZE);
	fs.close();
	for (int j = 0; j < SIZE; j++) {
		if (j % 3 == 0) {
			cout << "The integer value here is "<< aVec[j] <<" at position "<< j << endl;
			cout << "The ascii value here is " << int(aVec[j]) << endl;
		}
		else {

		}
	}
	system("PAUSE");
	return 0;

}

