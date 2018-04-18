#include <iostream>
#include <fstream>
#include <ostream>
#include <vector>
using namespace std;

int main() { 
	vector<int> theVec;
	char *x=new char[4];
	ifstream fs;
	fs.open("data.dat", ios::binary | ios::in);
	while (!fs.eof()) {
		fs.read(x, sizeof(int));
		theVec.push_back((int)*x);
	}
	float average=0 ;
	float sum=0;
	for (int i = 0; i < theVec.size(); i++) {
		cout << theVec[i] << endl;
		
	}
	cout << sum << endl;
	average = sum / theVec.size();
	cout << theVec.size()<<endl;
	cout << "The average of the data in this file is " << average << "." << endl;
	system("PAUSE");
	delete[] x;
	return 0;
}