#include "box.h"
#include <iostream>
#include <string>

Box::Box(int width, int height) :width_(width), height_(height), type_("Filled") {}
Box::Box(int width, int height, bool type) :width_(width), height_(height) {
	if (type) {
		type_ = "Filled";
	}
	else {
		type_ = "Hollow";
	}
}
std::string Box::type(){
	return type_;
}
int Box::getWidth(){
	return width_;
}
int Box::getHeight(){
	return height_;
}
std::string Box::type() const {
	return type_;
}
int Box::getWidth() const {
	return width_;
}
int Box::getHeight() const{
	return height_;
}
void Box::setWidth(int width){
	width_ = width;
}
void Box::setHeight(int height){
	height_ = height;
}
void Box::print(std::ostream &){
	if (type_ == "Filled") {
		for (int i = 0; i < height_; i++) {
			for (int j = 0; j < width_; j++) {
				std::cout << "x";
			}
			std::cout << std::endl;
		}
	}
	else {
		for (int i = 0; i < height_; i++) {
			for (int j = 0; j < width_; j++) {
				if (i = 0 || height_ - 2) {
					std::cout << "x";
				}
				else {
					if (j = 0 || j < width_ - 2) {
						std::cout << "x";
					}
					else {
						std::cout << " ";
					}
				}
			}
		}
		std::cout << std::endl;
	}
}

void Box::print(std::ostream &) const {
	if (type_ == "Filled") {
		for (int i = 0; i < height_; i++) {
			for (int j = 0; j < width_; j++) {
				std::cout << "x";
			}
			std::cout << std::endl;
		}
	}
	else {
		for (int i = 0; i < height_; i++) {
			for (int j = 0; j < width_; j++) {
				if (i = 0 || height_ - 2) {
					std::cout << "x";
				}
				else {
					if (j = 0 || j < width_ - 2) {
						std::cout << "x";
					}
					else {
						std::cout << " ";
					}
				}
			}
		}
		std::cout << std::endl;
	}
}