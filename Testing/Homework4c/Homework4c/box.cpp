#include "box.h"

/*
Hal DiMarchi
5/6/2016
Souce file for box classes
*/
//General Box functions
int Box::getWidth() {
	return width_;
}
int Box::getWidth() const {
	return width_;
}
int Box::getHeight() {
	return height_;
}
int Box::getHeight() const {
	return height_;
}
void Box::setWidth(int width) {
	width_ = width;
}
void Box::setHeight(int height) {
	height_ = height;
}

//Filled Box functions
void FilledBox::print(std::ostream & os) const {
	for (int i = 0; i < height_; i++) {
		for (int j = 0; j < width_; j++) {
			os << "X";
		}
		os << std::endl;
	}
	os << std::endl;
}
std::string FilledBox::type() const {
	return "Filled";
}


//Hollow Box Functions
void HollowBox::print(std::ostream & os) const {
	for (int i = 0; i < height_; i++) {
		for (int j = 0; j < width_; j++) {
			if (i == 0 || i == height_ - 1) {
				os << "X";
			}
			else {
				if (j == 0 || j == width_ - 1) {
					os << "X";
				}
				else {
					os << " ";
				}
			}
		}
		os << std::endl;
	}
	os << std::endl;
}

std::string HollowBox::type() const {
	return "Hollow";
}

//Checkered Box Functions
void CheckeredBox::print(std::ostream & os) const {
	int spot = 1;
	for (int i = 0; i < height_; i++) {
		for (int j = 0; j < width_; j++) {
			if (spot == 1) {
				os << "X";
				spot = 0;
			}
			else if (spot == 0) {
				os << " ";
				spot = 1;
			}
		}
		os << std::endl;
	}
	os << std::endl;
}

std::string CheckeredBox::type() const {
	return "Checkered";
}
