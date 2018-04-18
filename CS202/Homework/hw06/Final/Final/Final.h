#pragma once
#include <iostream>
#include <iomanip>
#include <vector>

class Money {
public:
	Money() :cents(0) {};
	Money(Money & Orig);
	Money(int dollars, int change);
	Money(double dollars);

	//money mutators
	Money & operator=(const Money & Orig);
	Money & operator+=(const Money & rhs);
	Money & operator-=(const Money & rhs);
	friend Money operator+(const Money & lhs,const Money & rhs);
	friend Money operator-(const Money & lhs, const Money & rhs);
	friend Money operator*( const Money & lhs, double mult);
	friend Money operator*(double mult, const Money & rhs);
	Money & operator*=(double mult);
	friend Money operator/(const Money & lhs, double div);
	Money & operator/=(double div);
	//accesor function
	int showcents();
	int showcents() const;

	//?
	friend double operator*(double mult, Money & rhs);
	//comparison operators
	friend const bool & operator==(const Money & lhs, const Money & rhs);
	friend const bool & operator!=(const Money & lhs, const Money & rhs);
	friend const bool & operator<(const Money & lhs, const Money & rhs);
	friend const bool & operator>(const Money & lhs, const Money & rhs);
	friend const bool & operator<=(const Money & lhs, const Money & rhs);
	friend const bool & operator>=(const Money & lhs, const Money & rhs);
	//print operators
	friend std::ostream &operator<<(std::ostream & os,const Money & rhs);

private:
	signed int cents;

};
//RAIIPTR RAIIPTR RAIIPTR RAIIPTR

template <class T>
class RAIIPtr{

public:
	RAIIPtr<T>( T* foo) {
		object = *foo;
		rawptr = foo;
		
	}
	~RAIIPtr<T>(){
		delete rawptr;
	}
	T & operator*() {
		return object;
	}
	
	 T * operator->() {
		 return rawptr;
	}
	 
	friend std::ostream & operator<<(std::ostream & os,  RAIIPtr<T> & rhs) {
		os << *rhs << std::endl;
	}

	
private:
	RAIIPtr<T>(RAIIPtr<T> & fudge) {};
	RAIIPtr<T> &operator=(RAIIPtr<T> & rhs) {};
	T object;
	T* rawptr;
	
	
};

//RAIIPTR RAIIPTR RAIIPTR RAIIPTR
template <typename G>

std::ostream & printVector(std::ostream & os, std::vector<G> foo) {
	for (int i = 0; i < foo.size(); i++) {
		os << foo[i] << std::endl;
	}
	return os;
}
