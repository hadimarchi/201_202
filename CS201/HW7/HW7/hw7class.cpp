#include "stdafx.h"
#include <iostream>
#include "hw7class.h"
using namespace std;

Rational::Rational() {
	denom_ = 1;
	numer_ = 1;
}
Rational::Rational(int x, int y) {
	numer_ = x;
	denom_ = y;

}
Rational::getNumerator() {
	return numer_;

}
Rational::getDenominator() {
	return denom_;
}

Rational::setnumer(int numer) {
	numer_ = numer;
}
Rational::setdenom(int denom) {
	denom_ = denom;
}
Rational::add(Rational &rhs){
	Rational rv;
	rv.setnumer((numer_*rhs.getDenominator()) + (rhs.getNumerator()*denom_));
	rv.setdenom((denom*rhs.getDenominator()));


}
Rational::sub(Rational &rhs) {
	Rational rv;
	rv.setnumer((numer_*rhs.getDenominator()) - (rhs.getNumerator()*denom_));
	rv.setdenom((denom_*rhs.getDenominator()));
	

}
Rational::print() {
	cout << "The rational number is " << numer_ << " / " << denom_ << endl;
}
