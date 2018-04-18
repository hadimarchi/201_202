// Insertion Sort.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <ctime>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;
//BB: In the future, please dont include all the files from visual studio. the only file that is required is the .cpp and header files

void insertsort(vector<int>&data)
{
	int i, j, temp;

	for (i = 1; i < data.size(); i++)
	{
		j = i;
		temp = data[i];
		while (j > 0 && temp < data[j - 1])
		{
			data[j] = data[j - 1];
			j--;
		}
		data[j] = temp;
	}
}
int binsearch(vector<int>&data,int x) {
	int steps = 0;
	int beg = 0;
	int end = data.size()-1;
	int mid = (end-beg) / 2;
	while (beg <= end&&data[mid]!= x)
	{
		if (data[mid] < x) {
			beg = mid + 1;
		}
		else {
			end = mid - 1;
		}
		mid = (beg + end) / 2;
		steps++;
	}
		
		if(data [mid]==x){
		cout<<"This value is in slot " << mid << " of the array, if the first slot is known as slot 0" << endl;

	}
	cout << "The number of steps it took to find this is " << steps << endl;
	return 0;
}
int SeedRand(vector<int> &data)
{
	int i;
	for (i = 0; i < data.size(); i++) {
		data[i]= rand()%100+1;
	}
	return 0;
}

int main()
{
	int size,n;
	cout << "How big do you want the vector to be?" << endl;
		cin >> size;
		vector <int> OurVec(size);
		SeedRand(OurVec);
		cout << "This is our unsorted vector" << endl;
		for (int val : OurVec) {
			cout << val << endl;
		}
		cout << "This is our sorted vector" << endl;
		insertsort(OurVec);
		for (int val : OurVec) {
			cout << val << endl;
		}
		cout << "Enter in an element you'd like to find" << endl;
		cin >> n;
		binsearch(OurVec,n);


    return 0;
}

