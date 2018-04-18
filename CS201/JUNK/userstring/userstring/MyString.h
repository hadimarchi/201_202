#ifndef USERSTRING_H_INCLUDED
#define USERSTRING_H_INCLUDED
#include <iostream>

class MyString {
	public:
		MyString() : size_(0), data_(NULL)
		{}
		MyString(int s);
		MyString(const MyString &Orig);
		~MyString();
		unsigned int size();
		unsigned int size() const;
		void resize(int newsize);
		MyString & operator=(const MyString &rhs);
		char & operator[](int indx);
		char & operator[](int indx) const;
		friend MyString & operator+(MyString & lhs, MyString & rhs);
		bool & operator==(const MyString & rhs);
		bool & operator!=(const MyString & rhs);
		friend std::ostream & operator<<(std::ostream & lhs, const MyString & rhs);

		          


	private:
		unsigned int size_;
		char *data_;
};












#endif
