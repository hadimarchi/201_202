#pragma once
#include <iostream>
#include <iomanip>
#include <vector>
/*
Final.h
Hal DiMarchi
5/5/16
Header file for class Money
Source file for templated PrintVector
Source file for class RAIIPtr
*/
class Money {
public:
	//money constructors
	Money() :cents_(0) {};
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

	//mutiplies a mult by a money object
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
	signed int cents_;

};
//RAIIPTR RAIIPTR RAIIPTR RAIIPTR

template <class T>
class RAIIPtr{

public:
	RAIIPtr<T>( T* foo):rawptr_(foo) {}
	~RAIIPtr<T>(){
	delete rawptr_;
	}
	T & operator*() {
		return *rawptr_;
	}
	
	 T * operator->() {
		 return rawptr_;
	}
	 
	friend std::ostream & operator<<(std::ostream & os,  RAIIPtr<T> & rhs) {
		os << *rhs << std::endl;
	}

	
private:
	RAIIPtr<T>(RAIIPtr<T> & fudge) {};
	RAIIPtr<T> &operator=(RAIIPtr<T> & notimportant) {};
	T* rawptr_;										//The RAIIPtr takes a dumb pointer, and manages its memory
	
	
};

//RAIIPTR RAIIPTR RAIIPTR RAIIPTR
template <typename G>
//printVector printVector printVector printVector
std::ostream & printVector(std::ostream & os, std::vector<G> foo) { //takes in G vector, prints accordingly to an os stream
	for (int i = 0; i < foo.size(); i++) {
		os << foo[i] << std::endl;
	}
	return os;
}
