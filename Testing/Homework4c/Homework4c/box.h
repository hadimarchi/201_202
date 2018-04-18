#pragma once
#include <iostream>
#include <string>
/*
Hal DiMarchi
5/6/2016
Header file for box classes
*/
class Box {
public:
	Box() :width_(1), height_(1) {}
	Box(int w, int h) :width_(w), height_(h) {}
	int getWidth();
	int getWidth() const;
	int getHeight();
	int getHeight() const;
	void setWidth(int width);
	void setHeight(int height);
	virtual void print(std::ostream & os) const
	{
		os << "I am dumb" << std::endl;

	}
	virtual std::string type() {

		return "NOTYPE";
	}
	friend std::ostream &operator<<(std::ostream & os, const Box & b) {
		return os;
	}
	friend std::ostream &operator<<(std::ostream & os, Box & b) {
		return os;
	}
	//friend std::ostream &operator<<(std::ostream & os, Box & b);
	~Box() {
		width_ = 0;
		height_ = 0;
	}
protected:
	unsigned int width_;
	unsigned int height_;
};

class FilledBox :public Box {
public:
	FilledBox() {}
	FilledBox(int w, int h) {
		setWidth(w);
		setHeight(h);
	}
	
	void print(std::ostream & os) const;
	std::string type() const;

};
class HollowBox :public Box {
public:
	HollowBox() {}
	HollowBox(int w, int h) {
		setWidth(w);
		setHeight(h);
	}
	
	void print(std::ostream & os) const;
	std::string type() const;
};
class CheckeredBox :public Box {
public:
	CheckeredBox() {}
	CheckeredBox(int w, int h) {
		setWidth(w);
		setHeight(h);
	}
	
	void print(std::ostream & os) const;
	std::string type() const;

};

Box * boxFactory(char c, int w, int h) {
	if (c == 'f') {
		FilledBox bFF(w, h);
		Box *ptr = &bFF;
		return ptr;

	}
	else if (c == 'h') {
		HollowBox bFH(w, h);
		Box *ptr = &bFH;
		return ptr;
	}
	else if (c == 'c') {
		CheckeredBox bFC(w, h);
		Box *ptr = &bFC;
		return  ptr;

	}
}