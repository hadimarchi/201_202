// HW6.cpp : Defines the entry point for the console application.
//

#include <stdlib.h>
#include <ctime>
#include <iostream>
#include "HW6.h"
#include <cstring>

using namespace std;



int * reverseArray(const int arry[], const int size) {
	int *ptr = new int[size];
	for (int i = 1; i < size+1; i++){
		*(ptr + i) = arry[size - i];
		cout << *(ptr + i) << endl;
	
	}
	return ptr;


}


