#ifndef LAB5_H_INCLUDED
#define LAB5_H_INCLUDED
class TwoD 
{
public:
	TwoD() :x_(0), y_(0)
	{}
	TwoD(int x, int y) : x_(x), y_(y)
	{}
	int getX();
	int getY();
	void setX(int x);
	void setY(int y);
	double distance(TwoD);
protected:
	int x_;
	int y_;
};
class ThreeD : public TwoD
{
public:
	ThreeD() : TwoD(), z_(0)
	{}
	ThreeD(int x, int y, int z) : TwoD(x, y), z_(z)
	{}
	int getZ();
	void setZ();
	double distance(ThreeD);
private:
	int z_;
};





#endif
