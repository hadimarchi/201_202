#include "stdafx.h"
#include <iostream>
#include "Crypto.h"
#include <cstring>
#include <cstdlib>

using namespace std;
int getLength(char lengthtemp[]) {
	int i = 0;
	while (lengthtemp[i] != '\0') {
		i++;
	}
	return i;
}
char decryptMorse(char morse[]) {
	int k = 0;	//spot we start at in the decoded array
	int length = 1;	//initial length of the decoded array
	int size = getLength(morse); //creates variable size, is equal to the length of the more char array
	char *temp = new char[1]; //temp array, equal to morse array in size (might need to change that? does null data get used when using to assign another array?)
	char *decoded = new char[255]; //creates the array for the plaintext decoded message.
	decoded = S[0];
	temp = S[0];
	for (int i = 0; i < size; i++) { //top for loop, runs through all of morse code message
		if (morse[i] = '.') {
			*temp = strcat_s(temp, 1, "."); //sets temp equal to temp plus the next character in the morse code char array
		}
		else {
			temp[0] = strcat_s(temp, 1, "-");
		}
		for (int j = 0; j < 26; j++) { //second for loop, runs through morse code library and compares
			if (*temp == (((*M[j]))) || (*Mstart[j])) { //if the temp array is equal to part of that library
				decoded[k] = *B[j];              //assign plaintext version of that morse character to decoded array(why no *operator? Throws error)
				k++;						//move to the next spot in the decoded array
				length++;					//increases length by 1 so that there is room for the next character
				delete[] temp;					 //delete temp 
				char *temp = new char[1];	//recreate temp, needs to be empty so it can be the next morse character in our morse array
				temp[0] = *S[0];
			}
			else if (*temp == MS[0]) {          //if temp equals morse for space
				decoded[k] = *S[0];				//assign space to decoded array
				k++;	 							//move to next spot of k
				length++;						//increases length of decoded array
				delete[] temp;					//delete temp
				char *temp = new char[1];		//recreate temp
				temp[0] = *S[0];
			}
			else {									//if none of this is true we need to add another character of the morse array, but nothing else needs to happen

			}
		}
	}

	length--;	//decreases length by 1, as loops above will inevitably create an extra(blank) character
	int l = 0;
	while (decoded[l] != NULL) {
		return decoded[l];
		l++;
	}
	delete[] decoded;
	delete[] temp;
}
