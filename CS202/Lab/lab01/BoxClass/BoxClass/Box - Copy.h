#pragma once
#ifndef BOX_H_INCLUDED
#define BOX_H_INCLUDED
#include "stdafx.h"
#include <iostream>
using namespace std;
class box {
public:
	box();
	box(double l);
	double getlength();
	void setlength(double l);
	static int getcount();
	void printbox();
	~box();
private:
	double length;
	static int boxcount;
};











#endif