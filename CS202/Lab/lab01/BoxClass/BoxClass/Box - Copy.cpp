#include "Box.h"

int box::boxcount = 0;
box::box() {
	length = 0;
	boxcount++;
}
box::box(double l) {
	length = l;
	boxcount++;
}
double box::getlength() {
	return length;
}
void box::setlength(double l)
{
	length = l;
}
static int box::getcount() {
	return boxcount;
}
void box::printbox() {
	for (int j = 0; j < length; j++) {
		for (int i = 0; i < length; i++) {
			cout << "X" << endl;
		}
		cout << "\n" << endl;
	}
}
box::~box() {
	boxcount--;
}