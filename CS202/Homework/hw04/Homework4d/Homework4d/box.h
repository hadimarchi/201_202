#pragma once
#pragma once
#include <iostream>
#include <string>
#include <sstream>
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
	virtual std::ostream & print(std::ostream & os) const
	{
		os << "I am dumb" << std::endl;
		return os;
	}
	virtual std::string type() {

		return "NOTYPE";
	}
	friend std::ostream &operator<<(std::ostream & os, const Box & b) {
		b.print(os);
		return os;
	}
	friend std::ostream &operator<<(std::ostream & os, Box & b) {
		b.print(os);
		b.print(std::cout);
		return os;
	}
	
	~Box() {
	}
protected:
	unsigned int width_;
	unsigned int height_;
};

class FilledBox :public Box {
public:
	FilledBox() {
		setWidth(1);
		setHeight(1);
	}
	FilledBox(int w, int h) {
		setWidth(w);
		setHeight(h);
	}
	std::ostream & print(std::ostream & os) const;
	std::string type() const;

};
class HollowBox :public Box {
public:
	HollowBox() {
		setWidth(1);
		setHeight(1);
	}
	HollowBox(int w, int h) {
		setWidth(w);
		setHeight(h);
	}

	std::ostream & print(std::ostream & os) const;
	std::string type() const;
};
class CheckeredBox :public Box {
public:
	CheckeredBox() {
		setWidth(1);
		setHeight(1);
	}
	CheckeredBox(int w, int h) {
		setWidth(w);
		setHeight(h);
	}

	std::ostream &print(std::ostream & os) const;
	std::string type() const;

};

Box * boxFactory(char c, int w, int h);