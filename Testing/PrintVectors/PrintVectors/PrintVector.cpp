#include <iostream>
#include <vector>


template <typename G>

std::ostream & PrintVector(std::ostream & os, std::vector<G> foo) {
	for (int i = 0; i < foo.size(); i++) {
		os << foo[i] << std::endl;
	}
	return os;
}
int main() {
	std::vector<int> integer;
	integer.assign(10, 100);
	PrintVector(std::cout, integer);
	

	std::vector<char> character;
	character.assign(10, 'a');
	PrintVector(std::cout, character);
	system("PAUSE");
}