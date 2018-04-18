#ifndef HW7CLASS_H_INCLUDED
#define HW7CLASS_H_INCLUDED
#include "stdafx.h"
#include <iostream>
using namespace std;

class Rational {
public:
	//constructors
	Rational();
	Rational(int x, int y);
	//accesor functions
	int getNumerator();
	int getDenominator();
	//mutator functions
	void setnumer(int numer);
	void setdenom(int denom);
	//add and subtract functions
    Rational add(Rational &rhs);
	Rational sub(Rational &rhs);
	~Rational() {
		cout << "Destroyed" << endl;
	}


private:
	int numer_;
	int denom_;

};


#endif
