//BB: missing top of file comments
// BoxClass.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Box.h"
using namespace std;



int main()
{
	box a(10);
	box::getcount();
	a.getlength();
	a.setlength(7);
	a.printbox();

    return 0;
}

