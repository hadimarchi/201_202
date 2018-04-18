// Lab1030.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "vector"
using namespace std;
void VectorPointerBullshit(vector<int> &OurVec, int* iptr);


int main()
{
	int size;
	cout << "Give me a size" << endl;
	cin >> size;
	vector<int> data(size);
	int *ptr = &data[0];
	VectorPointerBullshit(data, ptr);
	system("PAUSE");
}
	void VectorPointerBullshit(vector<int> &OurVec, int* iptr) {
		for (int i = 0; i<OurVec.size()-1; i++)
		{
			OurVec[i] = rand() % 100;
			cout <<OurVec[i] << endl;
			iptr = &OurVec[i];
			iptr++;
			cout << *iptr << endl;
		}
		cout << "Now deleting this vector" << endl;
			delete[] iptr;
	
	}
	
	
	
