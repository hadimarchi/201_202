// ActualLab1030.cpp : Defines the entry point for the console application.
//


#include <iostream>
using namespace std;

int main()

{
	
		int size;
		cout << "Give us a size for an array" << endl;
		cin >> size;
		int * iptr = new int[size];
        //BB: this seems right, but it actually does nothing. If iptr == 0, then this is true, it prints that something went wrong, and then continues to do it anyways.
        //BB: furthermore, there is no guarantee that the pointer is null when initialized. Its going to be whatever was in the space before you asked for a pointer
        //BB: Finally, new throws an exception if it doesn't allocate properly, so the program ends there
		if (!iptr)
		{
				cout << "Something went wrong" << endl;
		}

		for (int i = 0; i<size; ++i)
		{
            //BB: iptr[i] is a short hand for *(iptr+i)
			*(iptr + i) = rand() % 100;
				cout << *(iptr + i) << endl;
		}
		delete[] iptr;
}
