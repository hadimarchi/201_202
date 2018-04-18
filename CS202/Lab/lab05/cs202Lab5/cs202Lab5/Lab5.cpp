#include<iostream>
#include "Lab5.h"


int TwoD::getX(){
	return x_;
}
int TwoD::getY(){
	return y_;
}
void TwoD::setX(int x){
	x_ = x;
}
void TwoD::setY(int y){
	y_ = y;
}
double TwoD::distance(TwoD t){
	double rv;
	rv = sqrt((x_-t.getX()) ^ 2 + (y_-t.getY()) ^ 2);
	return rv;
}
int ThreeD::getZ(){
	return z_;
}
void ThreeD::setZ(){
}
double ThreeD::distance(ThreeD t){
	double rv;
	rv = sqrt((x_ - t.getX()) ^ 2 + (y_ - t.getY()) ^ 2 + (z_ - t.getZ()) ^ 2);
	return rv;
}
int main() {
	TwoD a2D(9, 10);
	TwoD b2D(13, 17);
	std::cout << a2D.distance(b2D) << std::endl;
	ThreeD a3D(9, 10, 11);
	ThreeD b3D(13, 17, 4);
	std::cout << a3D.distance(b3D) << std::endl;
	system("PAUSE");
	return 0;
}