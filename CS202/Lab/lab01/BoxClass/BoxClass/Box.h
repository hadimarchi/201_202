//BB: missing top of file comments
#ifndef BOX_H_INCLUDED
#define BOX_H_INCLUDED
#include <iostream>
using namespace std;
class box {
public:
	box();
	box(int l);
	int getlength();
	void setlength(int l);
	static int getcount();
	void printbox();
	~box();
	
private:
	static int boxcount;
	int length;
	
};











#endif
