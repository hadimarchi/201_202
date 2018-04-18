#pragma once
#include <iostream>
#include <iomanip>
class Money {
public:
	Money() :cents(0) {};
	Money(Money & Orig);
	Money(int dollars, int change);
	Money(double dollars);

	//money mutators
	Money & operator=(Money & Orig);
	Money & operator+=(int change);
	Money & operator-=(int change);
	Money & operator+(Money & rhs);
	Money & operator-(Money & rhs);
	friend Money operator*(Money & lhs, double mult);
	Money & operator*=(double mult);
	friend Money operator/(Money & lhs, double div);
	Money & operator/=(double div);
	//accesor function
	int showcents();
	//?
	friend double operator*(double mult, Money & rhs );
	//comparison operators
	friend const bool & operator==(Money & lhs, Money & rhs);
	friend const bool & operator!=(Money & lhs, Money & rhs);
	friend const bool & operator<(Money & lhs, Money & rhs);
	friend const bool & operator>(Money & lhs, Money & rhs);
	friend const bool & operator<=(Money & lhs, Money & rhs);
	friend const bool & operator>=(Money & lhs, Money & rhs);
	//print operators
	friend std::ostream &operator<<(std::ostream & os, Money & rhs);

private:
	signed int cents;

};