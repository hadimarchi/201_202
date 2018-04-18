#include "Final.h"
#include <iostream>
#include <math.h>
/*
Final.cpp
Hal DiMarchi
5/5/16
Source file for class Money
*/

//MONEY MONEY MONEY MONEY MONEY MONEY MONEY
// generally I convert between dollar and cents amounts
// by multiplying or dividing by 100
// math.h functions are used to round correctly

//Money Constructors
Money::Money(Money & Orig) {
	cents_ = Orig.showcents();
}
Money::Money(int dollars, int change) {
	cents_ = dollars * 100 + change;
}
Money::Money(double dollars) {
	int dollarsincents = (floor(dollars) * 100);
	int centsincents = round(((dollars * 100) - dollarsincents));
	cents_ = dollarsincents + centsincents;
}
//Money mutators
//assignment operator
Money & Money::operator=(const Money & Orig) {
	cents_ = Orig.showcents();
	return *this;
}
//arithemetic operators (first two assign to implicent argument, second two send result to a new money object)
Money & Money::operator+=(const Money & rhs) {
	cents_ += rhs.showcents();
	return *this;
}
Money & Money::operator-=(const Money & rhs) {
	cents_ = cents_ - rhs.showcents();
	return *this;
}
Money operator+(const Money & lhs, const Money & rhs) {
	double tempcents = lhs.showcents() + rhs.showcents();
	int dollarsindollars = floor(tempcents / 100);
	int dollarsincents = dollarsindollars * 100;
	int centsincents = round(tempcents - dollarsincents);
	Money rv(dollarsindollars, centsincents);
	return rv;
}
Money operator-(const Money & lhs, const Money & rhs) {
	double tempcents = lhs.showcents() - rhs.showcents();
	int dollarsindollars = floor(tempcents / 100);
	int dollarsincents = dollarsindollars * 100;
	int centsincents = round(tempcents - dollarsincents);
	Money rv(dollarsindollars,centsincents);
	return rv;
}
//multiplication and division operators
//first two of multiplication and first two of division send result to a new money object, the other two assign
Money operator*(const Money & lhs, double mult) {
	double tempcents = (lhs.showcents()*mult);
	int dollarsindollars = floor(tempcents / 100);
	int dollarsincents = dollarsindollars * 100;
	int centsincents = round(tempcents - dollarsincents);

	Money rv(dollarsindollars, centsincents);
	return rv;
}
//this duplicate of the previous functions allows for rearrangement of the money object, and its multiplier
Money operator*(double mult, const Money & rhs) {
	double tempcents = (rhs.showcents()*mult);
	int dollarsindollars = floor(tempcents / 100);
	int dollarsincents = dollarsindollars * 100;
	int centsincents = round(tempcents - dollarsincents);

	Money rv(dollarsindollars, centsincents);
	return rv;
}

Money & Money::operator*=(double mult) {
	double tempcents = this->showcents()*mult;
	int dollarsincents = floor(tempcents / 100) * 100;
	int centsincents = round(tempcents - dollarsincents);
	cents_ = dollarsincents + centsincents;
	return *this;
}
Money operator/(const Money & lhs, double div) {
	double tempcents = lhs.showcents() / div;
	int dollarsincents = floor(tempcents / 100) * 100;
	int centsincents = round(tempcents - dollarsincents);
	int forMoneyd = dollarsincents / 100;
	int forMoneyc = centsincents;
	Money rv(forMoneyd, forMoneyc);
	return rv;
}
Money operator/(double div, const Money & rhs) {
	double tempcents = rhs.showcents() / div;
	int dollarsincents = floor(tempcents / 100) * 100;
	int centsincents = round(tempcents - dollarsincents);
	int forMoneyd = dollarsincents / 100;
	int forMoneyc = centsincents;
	Money rv(forMoneyd, forMoneyc);
	return rv;
}
Money & Money::operator/=(double div) {
	double tempcents = this->showcents()/ div;
	int dollarsincents = floor(tempcents / 100) * 100;
	int centsincents = round(tempcents - dollarsincents);
	cents_ = dollarsincents + centsincents;
	return *this;
}
//accesor function
int Money::showcents() {
	return cents_;
}
int Money::showcents() const {
	return cents_;
}
//multiplies a double by a money object to get a new double
double operator*(double mult, Money & rhs) {
	double result;
	result = mult*rhs.showcents();
	return result;

}
//comparison operators
const bool & operator==(const Money & lhs, const Money & rhs) {
	if (lhs.showcents() == rhs.showcents()) {
		return true;
	}
	else {
		return false;
	}
}
const bool & operator!=(const Money & lhs, const Money & rhs) {
	if (lhs == rhs) {
		return false;
	}
	else {
		return true;
	}
}
const bool & operator<(const Money & lhs, const Money & rhs) {
	if (lhs.showcents() < rhs.showcents()) {
		return true;
	}
	else {
		return false;
	}
}
const bool & operator>(const Money & lhs, const Money & rhs) {
	if (lhs.showcents() > rhs.showcents()) {
		return true;
	}
	else {
		return false;
	}
}
const bool & operator<=(const Money & lhs, const Money & rhs) {
	if (lhs.showcents() <= rhs.showcents()) {
		return true;
	}
	else {
		return false;
	}
}
const bool & operator>=(const Money & lhs, const Money & rhs) {
	if (lhs.showcents() >= rhs.showcents()) {
		return true;
	}
	else {
		return false;
	}
}
//print operator
std::ostream &operator<<(std::ostream & os, const Money & rhs) {
	signed int dollars = rhs.showcents() / 100;
	signed int printchange = rhs.showcents() % 100;
	if (printchange < 0) {
		printchange = printchange*(-1);
	}
	else {}
	if (dollars < 0) {                                                            //checks to see if dollars are negative for proper formatting
		if (printchange < 10) {													  //checks to see if cents are single digit for proper formatting
			os << "-$" << dollars*-1 << ".0" << printchange;
		}
		else {																	//if there are more then ten cents there are no special formatting considerations
			os << "-$" << dollars*-1 << "." << printchange;
		}
	}
	else if (dollars >= 0) {													  //handles positive dollars
		if (printchange < 10) {                                                   //checks to see if cents are single digit for proper formatting
			os << "$" << dollars << ".0" << printchange;
		}
		else {																	  // //if there are more then ten cents there are no special formatting considerations
			os << "$" << dollars << "." << printchange;                         
		}
	}
	
	return os;
}
//MONEY MONEY MONEY MONEY MONEY MONEY MONEY

