#include "Final.h"
#include <iostream>
#include <math.h>
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
	int centsincents = round(((dollars*100) - dollarsincents));
	//std::cout << centsincents << std::endl;
	cents = dollarsincents + centsincents;
}
//Money mutators
Money & Money::operator=(Money & Orig) {
	cents = Orig.showcents();
	return *this;
}
Money & Money::operator+=(int change) {
	cents += change;
	return *this;
}
Money & Money::operator-=(int change) {
	cents -= change;
	return *this;
}
Money & Money::operator+(Money & rhs) {
	cents += rhs.showcents();
	return *this;
}
Money & Money::operator-(Money & rhs) {
	cents = cents - rhs.showcents();
	return *this;
}
Money operator*(Money & lhs,double mult) {
	 double tempcents = (lhs.showcents()*mult);
	 //std::cout << tempcents << std::endl;
	 int dollarsindollars = floor(tempcents / 100);
	 int dollarsincents = dollarsindollars * 100;
	 int centsincents = round(tempcents - dollarsincents);
	 //std::cout << centsincents << std::endl;
	
	 Money Temp(dollarsindollars,centsincents);
	return Temp;
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
Money operator/(Money & lhs, double div) {
	 double tempcents = lhs.showcents()/div;
	 //std::cout << lhs.showcents() << std::endl;
	 //std::cout << tempcents << std::endl;
	 int dollarsincents = floor(tempcents/100)*100;
	 //std::cout << dollarsincents << std::endl;
	 int centsincents = round(tempcents - dollarsincents);
	 //std::cout << centsincents << std::endl;
	 int forMoneyd = dollarsincents/100;
	 int forMoneyc = centsincents;
	 Money Temp(forMoneyd,forMoneyc);
	 return Temp;
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
//?
double operator*(double mult, Money & rhs) {
	double result;
	result = mult*rhs.showcents();
	return result;
	
}
//comparison operators
const bool & operator==(Money & lhs, Money & rhs) {
	if (lhs.showcents() == rhs.showcents()) {
		return true;
	}
	else {
		return false;
	}
}
const bool & operator!=(Money & lhs, Money & rhs) {
	if (lhs == rhs) {
		return false;
	}
	else {
		return true;
	}
}
const bool & operator<(Money & lhs, Money & rhs) {
	if (lhs.showcents() < rhs.showcents()) {
		return true;
	}
	else {
		return false;
	}
}
const bool & operator>(Money & lhs, Money & rhs) {
	if (lhs.showcents()>rhs.showcents()) {
		return true;
	}
	else {
		return false;
	}
}
const bool & operator<=(Money & lhs, Money & rhs) {
	if (lhs.showcents() <= rhs.showcents()) {
		return true;
	}
	else {
		return false;
	}
}
const bool & operator>=(Money & lhs, Money & rhs) {
	if (lhs.showcents() >= rhs.showcents()) {
		return true;
	}
	else {
		return false;
	}
}
//print operators
std::ostream &operator<<(std::ostream & os, Money & rhs) {
	signed int dollars = rhs.showcents() / 100;
	signed int printchange = rhs.showcents() % 100;
	if (printchange < 0) {
		printchange = printchange*(-1);
	}
	else {}
	os << "$" << dollars << "." << printchange << std::endl;
	//std::cout << "$" << dollars << "." << printchange << std::endl;
	return os;
}
int main() {
	
	int myDollars = 10;
	int myCents = 65;
	int friendDollars = 11;
	int friendCents = 77;
	std::cout << "testing two int constructor"<<std::endl;
	Money myWallet(myDollars, myCents);
	Money friendWallet(friendDollars, friendCents);
	std::cout << "made with two int constructor" << std::endl;
	std::cout << "First Money Object: "<<myWallet << std::endl;
	std::cout << "Second Money Object: "<<friendWallet << std::endl;
	std::cout << "testing adding two money objects: "<< friendWallet + myWallet << std::endl;
	std::cout << " testing subtracting two money objects, and display of negative amounts: "<< myWallet - friendWallet << std::endl;
	myWallet += 9050;
	std::cout <<"Adding 9050 cents to the First Money Object"<< myWallet << std::endl;
	std::cout << "Using copy constructor to create a third Money object equal to the first Money object"<<std::endl;
	Money bigWallet(myWallet);
	std::cout << "This is the third money object: " << bigWallet << std::endl;
	std::cout << "Testing == operator on first and third money object(should be 1): "<<(myWallet == bigWallet) << std::endl;
	std::cout << "Testing != operator on first and third money objects(shoudl be 0): " << (myWallet != bigWallet ) << std::endl;
	std::cout << "A Money object divided by 1.4(but not assigned): " << (myWallet / 1.4) << std::endl;
	std::cout << " A Money object multiplied by 1.4(but not assigned): " << (myWallet*1.4) << std::endl;
	std::cout << "The original Money object, unchanged "<<myWallet << std::endl;
	
	double branddollars = 45.6789;
	double brandldollars = 45.6723;
	Money BrandWallet(branddollars);
	std::cout << BrandWallet << std::endl;
	Money BrandSmallWallet(brandldollars);
	std::cout << BrandSmallWallet << std::endl;
	BrandSmallWallet *= 3.415;
	std::cout << BrandSmallWallet << std::endl;
	BrandSmallWallet /= 3.415;
	std::cout << BrandSmallWallet << std::endl;
	system("PAUSE");
}