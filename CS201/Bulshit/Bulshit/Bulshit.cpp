#include "stdafx.h"
#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;
char* B[26] = { "A","B","C","D","E","F","G","H","I","J","K","L","M",
"N","O","P","Q","R","S","T","U","V","W","X","Y","Z", };

char* M[26] = { ".- ", "-... ", "-.-. ", "-.. ", ". ", "..-. ", "--. ",
".... ", ".. ", ".--- ", "-.- ", ".-.. ", "-- ", "-. ", "--- ",
".--. ", "--.- ", ".-. ", "... ", "- ", "..- ", "...- ", ".-- ",
"-..- ", "-.-- ", "--.. " };
char* Mstart[26] = { " .- ", " -... ", " -.-. ", " -.. ", " . ", " ..-. ", " --. ",
" .... ", " .. ", " .--- ", " -.- ", " .-.. ", " -- ", " -. ", " --- ",
" .--. ", " --.- ", " .-. ", " ... ", " - ", " ..- ", " ...- ", " .-- ",
" -..- ", " -.-- ", " --.. " };
char* S[1] = { " " };
char* MS[1] = { "   " };
int main() {
	char * decoded = new char[];
	char morse[] = ".-";
	char a=morse[0];
	int k = 0;
	int i = 0;
	while (morse[i] != NULL)
	switch (a) {
	case '.- ' || ' .- ':
			decoded[k] = *B[0];
			k++;
			i++;
			delete &a;
			char a;
			break;
		case "-... "||" -... ":
			decoded[k] = *B[1];
			k++;
			i++;
			delete &a;
			char a;
			break;
		default:
			i++;
			char a+= morse[i];
			
	}
	char * decoded = new char[];
	decoded[0] = *B[3];
	decoded[1]= *B[4];
	int i = 0;
	while (i != 2) {
		cout << decoded[i] << endl;
		i++;
	}
	system("PAUSE");
}