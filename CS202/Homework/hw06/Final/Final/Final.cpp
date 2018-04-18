#include "Final.h"
#include <iostream>
#include <math.h>

//MONEY MONEY MONEY MONEY MONEY MONEY MONEY

//Money Constructors
Money::Money(Money & Orig) {
	cents = Orig.showcents();
}
Money::Money(int dollars, int change) {
	cents = dollars * 100 + change;
}
Money::Money(double dollars) {
	int dollarsincents = (floor(dollars) * 100);
	//std::cout << dollarsincents << std::endl;
	int centsincents = round(((dollars * 100) - dollarsincents));
	//std::cout << centsincents << std::endl;
	cents = dollarsincents + centsincents;
}
//Money mutators
Money & Money::operator=(const Money & Orig) {
	cents = Orig.showcents();
	return *this;
}
Money & Money::operator+=(const Money & rhs) {
	cents += rhs.showcents();
	return *this;
}
Money & Money::operator-=(const Money & rhs) {
	cents = cents - rhs.showcents();
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
Money operator*(const Money & lhs, double mult) {
	double tempcents = (lhs.showcents()*mult);
	//std::cout << tempcents << std::endl;
	int dollarsindollars = floor(tempcents / 100);
	int dollarsincents = dollarsindollars * 100;
	int centsincents = round(tempcents - dollarsincents);
	//std::cout << centsincents << std::endl;

	Money rv(dollarsindollars, centsincents);
	return rv;
}
Money operator*(double mult, const Money & rhs) {
	double tempcents = (rhs.showcents()*mult);
	//std::cout << tempcents << std::endl;
	int dollarsindollars = floor(tempcents / 100);
	int dollarsincents = dollarsindollars * 100;
	int centsincents = round(tempcents - dollarsincents);
	//std::cout << centsincents << std::endl;

	Money rv(dollarsindollars, centsincents);
	return rv;
}

Money & Money::operator*=(double mult) {
	double tempcents = cents*mult;
	//std::cout << tempcents << std::endl;
	int dollarsincents = floor(tempcents / 100) * 100;
	//std::cout << dollarsincents << std::endl;
	int centsincents = round(tempcents - dollarsincents);
	//std::cout << centsincents << std::endl;
	cents = dollarsincents + centsincents;
	return *this;
}
Money operator/(const Money & lhs, double div) {
	double tempcents = lhs.showcents() / div;
	//std::cout << lhs.showcents() << std::endl;
	//std::cout << tempcents << std::endl;
	int dollarsincents = floor(tempcents / 100) * 100;
	//std::cout << dollarsincents << std::endl;
	int centsincents = round(tempcents - dollarsincents);
	//std::cout << centsincents << std::endl;
	int forMoneyd = dollarsincents / 100;
	int forMoneyc = centsincents;
	Money Temp(forMoneyd, forMoneyc);
	return Temp;
}
Money operator/(double div, const Money & rhs) {
	double tempcents = rhs.showcents() / div;
	//std::cout << lhs.showcents() << std::endl;
	//std::cout << tempcents << std::endl;
	int dollarsincents = floor(tempcents / 100) * 100;
	//std::cout << dollarsincents << std::endl;
	int centsincents = round(tempcents - dollarsincents);
	//std::cout << centsincents << std::endl;
	int forMoneyd = dollarsincents / 100;
	int forMoneyc = centsincents;
	Money rv(forMoneyd, forMoneyc);
	return rv;
}
Money & Money::operator/=(double div) {
	double tempcents = cents / div;
	//std::cout << tempcents << std::endl;
	int dollarsincents = floor(tempcents / 100) * 100;
	//std::cout << dollarsincents << std::endl;
	int centsincents = round(tempcents - dollarsincents);
	//std::cout << centsincents << std::endl;
	cents = dollarsincents + centsincents;
	return *this;
}
//accesor function
int Money::showcents() {
	return cents;
}
int Money::showcents() const {
	return cents;
}
//?
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
	if (lhs.showcents()>rhs.showcents()) {
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
//print operators
std::ostream &operator<<(std::ostream & os, const Money & rhs) {
	signed int dollars = rhs.showcents() / 100;
	std::cout << dollars << std::endl;
	signed int printchange = rhs.showcents() % 100;
	if (printchange < 0) {
		printchange = printchange*(-1);
	}
	else {}
	if (dollars < 0) {
		if (printchange < 10) {
			os << "-$" << dollars*-1 << ".0" << printchange;
			std::cout << "-$" << dollars*-1 << ".0" << printchange << std::endl;
		}
		else {
			os << "-$" << dollars*-1 << "." << printchange;
			std::cout << "-$" << dollars*-1 << "." << printchange << std::endl;
		}
	}
	else if (dollars >= 0) {
		if (printchange < 10) {
			os << "$" << dollars << ".0" << printchange;
			std::cout << "$" << dollars << ".0" << printchange << std::endl;
		}
		else {
			os << "$" << dollars << "." << printchange;
			std::cout << "$" << dollars << "." << printchange << std::endl;
		}
	}
	
	//std::cout << "$" << dollars << "." << printchange << std::endl;
	return os;
}
//MONEY MONEY MONEY MONEY MONEY MONEY MONEY

