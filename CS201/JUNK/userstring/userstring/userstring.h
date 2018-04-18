#ifndef USERSTRING_H_INCLUDED
#define USERSTRING_H_INCLUDED
#include <iostream>
#include<exception>
template<typename T>
class MyString {
	public:
		MyString(int s) : size_(s), data_(new T[size_])
		{}
		MyString(const MyString &Orig)
		{
			size_ = Orig.size();
			data_ = new T[size_];
			for (int i = 0; i < size_; i++) {
				data_[i] = Orig[i];
			}
		}
		~MyString()
		{
			if (size_) {
				size_ = 0;
			}
			if (data_ != 0) {
				delete[] data_;
				data_ = 0;
			}
		}
		unsigned int size()
		{

			return size_;
		}
		unsigned int size() const
		{
			return size_;

		}

		void resize(int newsize)
		{
			int oldsize;
			char *newdata_ = new T[newsize];
			for (int i = 0; i < size(); i++) {
				newdata_[i] = data_[i];
			}
			delete[] data_;
			oldsize = size();
			size_ = newsize;
			data_ = new T[size_];
			for (int i = 0; i < size(); i++) {
				if (i < oldsize) {
					data_[i] = newdata_[i];
				}
			}
		}
		MyString & operator=(const MyString &rhs)
		{
			system("PAUSE");
			if ((this != &rhs)) {
				system("PAUSE");
				if (size_ != 0) {
					delete[] data_;
				}
				size_ = rhs.size();
				for (int i = 0; i < this->size(); i++) {
					data_[i] = rhs[i];
				}
			}
			return *this;
		}
		/*
		if(size!=0){
		delete [] data_;
		}
		size=rhs.size();
		data_=new char[size_];
		for(int i = 0; i<size_; i++){
		data_[i]=rhs[i]
		}

		*/
		std::ostream & operator<<(std::ostream & lhs, const MyString & rhs)
		{

			for (int i = 0; i < rhs.size(); ++i)
			{
				lhs << rhs[i];
			}
			return lhs;
		}

		std::ostream & operator<<(std::ostream & lhs, MyString & rhs)
		{

			for (int i = 0; i<rhs.size(); ++i)
			{
				lhs << rhs[i];
			}
			return lhs;
		}

		T & operator[](int indx)
		{
			return data_[indx];
		}
		T operator[](int indx) const
		{
			if (indx >= this.size()) {
				throw out_of_bounds("You're way out of line, this index does not exist");

			}
			return data_[indx];
		}
		MyString & operator+(MyString & lhs, MyString & rhs)
		{
			int offset;
			int size = lhs.size();
			MyString Temp(lhs.size() + rhs.size());
			for (int i = 0; i < lhs.size(); i++) {
				Temp[i] = lhs[i];
				offset = i;
			}

			for (int i = 0; i < rhs.size(); i++) {

				Temp[offset + i] = rhs[i];
			}
			Temp[Temp.size() - 1] = '\0';
			lhs = Temp;

			return lhs;
		}
		bool&operator==(const MyString & rhs) //might want to make a friend, accept two arguments
		{
			bool nottrue = false;
			bool ttrue = true;
			if (this->size() == rhs.size()) {
				for (int i = 0; i < rhs.size(); i++) {
					if (this[i] == rhs[i]) {

					}
					else {
						return nottrue;
					}
				}
				return  ttrue;
			}
			return nottrue;
		}
		bool & operator!=(const MyString & rhs)
		{
			bool nottrue = false;
			bool ttrue = true;;
			if (this == &rhs) {
				return nottrue;
			}
			else {
				return ttrue;
			}
		}

		          


	private:
		unsigned int size_;
		char *data_;
};












#endif
