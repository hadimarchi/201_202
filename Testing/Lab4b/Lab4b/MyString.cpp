#include "MyString.h"
using namespace std;

MyString::MyString(MyString & Orig) {
	size_ = Orig.size();
	data = new char[size_];
	*this = Orig;
	
}
unsigned int MyString::size() {
	return size_;

}
unsigned int MyString::size() const {
	return size_;

}
void MyString::resize(int newsize) {
	int oldsize_ = size_;
	char *newdata_ = new char[newsize];
	for (int i = 0; i < size(); i++) {
		newdata_[i] = data[i];
	}
	delete[] data;
	size_ = newsize;
	data = new char[size_];
	for (int i = 0; i < size(); i++) {
		if (i < oldsize_) {
			data[i] = newdata_[i];
		}
		else {
			data[i] = NULL;
		}
	}
}

MyString & MyString::operator = (const MyString & rhs) {
	if (this != &rhs) {
		delete[] data;
		size_ = rhs.size();
		data = new char[size_];
	
		for (int i = 0; i < size_; i++) {
			this->data[i] = rhs[i];
		}
	}
	
	return *this;
}
char & MyString::operator[](int s) {
	return data[s];
}
char & MyString::operator[](int s) const {
	return data[s];
}

ostream & operator<< (ostream & lhs, MyString & rhs) {
	
	for (int i = 0; i < rhs.size(); i++) {
		lhs << rhs[i];
	}
	return lhs;
}
const bool & operator==(MyString & lhs, MyString & rhs) {
	if (lhs.size() == rhs.size()) {
		for (int i = 0; i < lhs.size(); i++) {
			if (lhs[i] == rhs[i]) {

			}
			else{
				return false;
			}
		}
		return true;
	}
	else {
		return false;
	}
}

const bool & operator!=(MyString & lhs, MyString & rhs) {
	if (lhs == rhs) {
		return false;
	}
	else {
		return true;
	}
}
MyString & operator+ (MyString & lhs, MyString & rhs) {
	int temp = lhs.size();
	lhs.resize(lhs.size_ + rhs.size_);
	for (int i = temp; i < lhs.size(); i++) {
		lhs[i] = rhs[i - temp];
	}
	return lhs;
}
MyString::~MyString() {
	
	
	if (size_>0) {
		size_ = 0;
	}
	
		delete[] data;
}
