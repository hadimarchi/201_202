// BoxClass.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Box.h"
using namespace std;



int main()
{
	box a(5);
	box b(10);
box::getcount();
	a.getlength();
	a.printbox();
	a.setlength(6);
	a.getlength();
box::getcount();
	b.getlength();
	b.printbox();
	b.setlength(7);
	b.getlength();
	system("PAUSE");
    return 0;
}

