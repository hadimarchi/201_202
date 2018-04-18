// LabNov16.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <string>
using namespace std;


class Complex {
public:
	void setX(double x) {
		x_ = x;
	}
	void setY(double y) {
		y_ = y;
	}
	double getX() const {


		return x_;
	}
	double getY() const {
		return y_;
	}
	void printComp() {
		cout << getX() << " + " << getY() << "i" << endl;
	}
	//BB: this function was supposed to take a complex number class and return a complex number class.
	void addComplex(double x, double y, double a, double b) {
	
		setX(x + a);
		setY(y + b);
		//BB:while there is nothing technically wrong with returning a void function, its just never done, since its misleading.
		//BB:When you write something like that, it implicitly means that the function is supposed to return something.
		//BB:Futhermore, this is a void function, so returning at the end doesn't do anything
		return printComp();
	}
	void subComplex(double x, double y, double a, double b) {
		
		setX(x - a);
		setY(y - b);
		return printComp();
	}

private:
	double x_;
	double y_;
};
	int main()
	{
		Complex z;
		int use = 1;
		while (use == 1) {
			int choice;
			cout << "Tell me what you want to do!" << endl;
			cout << "Enter 1 to set the real part of a complex number," << endl;
			cout << "Enter 2 to set the imaginary part of a complex number," << endl;
			cout << "Enter 3 to print the currently entered complex number," << endl;
			cout << "Enter 4 to add two complex numbers, and 5 to find the difference of two complex numbers." << endl;
			cin >> choice;
			switch (choice)
		case 1:
			{
				double a;
				cout << "Enter the real value you wish to use" << endl;
				cin >> a;
				z.setX(a);
				break;
		case 2:
			double b;
			cout<<" Enter the imaginary value you wish to use" << endl;
			cin>> b;
			 z.setY(b);
			break;
		case 3:
			z.printComp();
			break;
		case 4:
			double c, d, e, f;
			cout << "Give me the real part of your first complex number." << endl;
			cin >> c;
			cout << "Give me the imaginary part of your first complex number." << endl;
			cin >> d;
			cout << "Give me the real part of your second complex number." << endl;
			cin >> e;
			cout << "Give me the imaginary part of your second complex number." << endl;
			cin >> f;
			z.addComplex(c,d,e,f);
			break;
		case 5:
			double g, h, i, j;
			cout << "Give me the real part of your first complex number." << endl;
			cin >> g;
			cout << "Give me the imaginary part of your first complex number." << endl;
			cin >> h;
			cout << "Give me the real part of your second complex number." << endl;
			cin >> i;
			cout << "Give me the imaginary part of your second complex number." << endl;
			cin >> j;
			z.subComplex(g,h,i,j);
			break;
		default:
			cout << "Sorry, you'll need to choose again." << endl;
			break;
			}
			cout << "Do you want do something else? Enter 1 for yes, and 0 for no." << endl;
			cin >> use;
		}
		return 0;
	}


	

	

