//BB: missing top of file comments

#include <iostream>
#include "Box.h"
using namespace std;
int box::boxcount = 0;
box::box() {
	length = 0;
    //BB: before I changed this, it was boxcout.
	boxcount++;
}
box::box(int l) {
	length = l;
	boxcount++;
}
int box::getlength() {
	return length;
}
void box::setlength(int l)
{
	length = l;
}
int box::getcount() {
	return boxcount;
}
void box::printbox() {
	for (int j = 0; j < length; j++) {
		for (int i = 0; i < length; i++) {
			cout << "X";
		}
		cout << "\n";
	}
}
box::~box() {
	boxcount--;
}
