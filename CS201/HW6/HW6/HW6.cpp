// HW6.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"
#include <stdlib.h>
#include <ctime>
#include <iostream>
#include "HW6.h"
using namespace std;



int * reverseArray(const int arry[], const int size) {
	int *ptr = new int[size];
	for (int i = 1; i < size+1; i++){
		*(ptr+i) = arry[size - i];
		cout << *(ptr + i) << endl;
	
	}
	return ptr;
}
int main()
{
	int size;
	cout << "Give us a size" << endl;
	cin >> size;
	int *iptr = new int[size];
	cout << "This is the original array" << endl;
	for (int i = 0; i < size; i++)
	{
		*(iptr + i) = rand() % 100 + i;

		cout << *(iptr + i) << endl;
	}
	cout << "This is the array in reverse" << endl;
	reverseArray(iptr, size);
	system("PAUSE");
    return 0;
}

