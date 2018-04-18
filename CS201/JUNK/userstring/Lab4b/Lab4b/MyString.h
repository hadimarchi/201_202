#ifndef MYSTRING_H
#define MYSTRING_H
#include <iostream>
#include <ostream>
#include <string>
#include <sstream>
using namespace std;

class MyString {
public:
	MyString() :size_(0), data(new char[size_]) {}
	MyString(unsigned int s) :size_(s), data(new char[size_]) {}
	MyString(MyString & Orig);
	~MyString();
	unsigned int size();
	unsigned int size() const;
	void resize(int newsize);
	MyString & operator = (const MyString & rhs);
	char & operator[](int s);
	char & MyString::operator[](int s) const;
	friend ostream & operator<< (ostream & lhs, MyString & rhs);
	friend const bool & operator==(MyString & lhs, MyString & rhs);
	friend const bool & operator!=(MyString & lhs, MyString & rhs);
	friend MyString & operator+ (MyString & lhs, MyString & rhs);
private:
	unsigned int size_;
	char *data;
};

MyString & operator+ (MyString & lhs, MyString & rhs);



#endif
