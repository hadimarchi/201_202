#include "hw1.h"
/*
	getIdFromFile breaks when not commented out. 
	numberChase appears to be receiving absurdly large values. 
	I'd really appreciate some substantial feedback on what I'm doing that these data types don't tolerate/data type conversions.
*/
int getIdFromFile(std::string file, std::istream &in, std::ostream &out) {
	std::vector<std::string> theVec;
	std::vector<std::string> theFile;
	std::vector<std::string> theFullFile;
	std::vector<std::string> theIDFile;
	char *x = new char[sizeof(std::string)];
	char *y = new char[sizeof(std::string)];
	char *z = new char[sizeof(std::string)];
	std::ifstream fs;

	fs.open(file, std::ios::in);
	if (!fs.good()) {
		return -1;
	}
	while (!in.eof()) {
		in.read(x, sizeof(std::string));
		theVec.push_back(x);

	}
	while (!fs.eof()) {
		fs.read(y, sizeof(std::string)); //should only take in five characters, reduce info to username for accurate comparison with istream in
		theFile.push_back(y);
		fs.read(z, sizeof(std::string));
		theFullFile.push_back(z);
	}

	/*	char *c = new char[sizeof(std::string)];
		char *d = new char[sizeof(std::string)];
		int j = 0;
		for (int i = 0; i < theFullFile.size(); i++) {
			(std::string)c = theFullFile[i];
			if (theFullFile[i] == " "&& theFullFile[i - 1] == "1" || "2" || "3" || "4" || "5" || "6" || "7" || "8" || "9" || "0") {
				theIDFile.push_back(d);

				delete c;
				delete d;
				char *c = new char[sizeof(std::string)];
				char *d = new char[sizeof(std::string)];
				j++;
			}
			else {
				if (c == "1" || "2" || "3" || "4" || "5" || "6" || "7" || "8" || "9" || "0") {
					d[j] += (char)c;
				}
				else {

				}
			}
		}


		int l = 0;
		for (int i = 0; i < theVec.size(); i++) {
			while (l < theVec.size() && theVec[i] != theFile[l]) {
				if (l = (theVec.size()) - 1) {
					std::cout << "error" << std::endl;
					l = theVec.size();
				}
				else {
					l++;
				}
			}
			if (theVec[i] == theFile[l]) {
				char *a = new char[sizeof(std::string)];
				(std::string) a = theIDFile[l];
				out.write(a, sizeof(std::string));
				delete a;
				l = 0;
			}
			else {
				l = 0;
			}

	}
	*/
	return 0;
}

	




void numberChase(std::string file, std::ostream &out) {
	std::vector<int> theVec;
	char *x = new char[sizeof(int)];
	std::ifstream fs;
	fs.open(file, std::ios::in||std::ios::binary);
	while (!fs.eof()) {
		fs.read(x, sizeof(int));
        //BB: you have to dereference these pointers in order to cast it as an int
        //BB: before I changed it, it was char* -> int, which doesn't make any sense
        //BB: so my compiler threw an error
		std::cout << (int)*x << std::endl;
		theVec.push_back((int)*x);
	}
	int i = 0;
	char *y = new char[sizeof(int)];
	while (i>0) {
		 i = theVec[i];
		 std::cout << i << std::endl;
		 std::cout << (int)i << std::endl;
		 if (i>0) {
			 y = (char*)i;
			 out.write(y, sizeof(int));
		 }
	}

}
