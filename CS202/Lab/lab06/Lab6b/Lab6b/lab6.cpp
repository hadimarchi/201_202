#include "lab6.h"
#include <iostream>
#include <stdexcept>

int main() {
	int j = 10;
	MyString<char> a(j);
	system("PAUSE");
	try {
		for (int i = 0; i < 11; i++) {
			system("PAUSE");
			return a[i];
			system("PAUSE");
		}
	}
	catch (std::out_of_range & e) {
		std::cout << e.what() << std::endl;
		system("PAUSE");
	}
	return 0;
}