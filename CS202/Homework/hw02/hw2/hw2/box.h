#ifndef BOX_H_INCLUDED
#define BOX_H_INCLUDED
#include <string>
#include <iostream>
class Box {
public:
	Box():width_(1), height_(1), type_("Filled") {}
	Box(int width, int height);
	Box(int width, int height, bool type);
	std::string type();
	std::string type() const;
	int getWidth();
	int getHeight();
	int getWidth() const;
	int getHeight() const;
	void setWidth(int width);
	void setHeight(int height);
	void print(std::ostream &);
	void print(std::ostream &) const;
private:
	int width_;
	int height_;
	std::string type_;
};


#endif
