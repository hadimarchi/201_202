#include "stdafx.h"
#include <cstring>
#include <iostream>

using namespace std;
char *B[26] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M",
               "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"};

char *M[26][6] = {".- ",   "-... ", "-.-. ", "-.. ",  ". ",    "..-. ", "--. ",
                  ".... ", ".. ",   ".--- ", "-.- ",  ".-.. ", "-- ",   "-. ",
                  "--- ",  ".--. ", "--.- ", ".-. ",  "... ",  "- ",    "..- ",
                  "...- ", ".-- ",  "-..- ", "-.-- ", "--.. "};
// const char *Mpointer = new char[26]{ '.-', '-...', '-.-.', '-..', '.',
// '..-.', '--.', '....', '..', '.---', '-.-', '.-..', '--', '-.', '---', '.--.',
// '--.-', '.-.', '...', '-', '..-', '...-', '.--', '-..-', '-.--', '--..' };
// char *Mpointerspace = new char[135]{" .-  -...  -.-.  -..  .  ..-.  --.  ....
// ..  .---  -.-  .-..  --  -.  ---  .--.  --.-  .-.  ...  -  ..-  ...-  .--
// -..-  -.--  --.. "};
char *Mstart[26][7] = {
    " .- ",   " -... ", " -.-. ", " -.. ",  " . ",    " ..-. ", " --. ",
    " .... ", " .. ",   " .--- ", " -.- ",  " .-.. ", " -- ",   " -. ",
    " --- ",  " .--. ", " --.- ", " .-. ",  " ... ",  " - ",    " ..- ",
    " ...- ", " .-- ",  " -..- ", " -.-- ", " --.. "};
char *S[1] = {" "};
char *MS = new char[4]{"   "};
int getLength(char lengthtemp[]) {
  int i = 0;
  while (lengthtemp[i] != '\0') {
    i++;
  }
  return i;
}
char *decryptMorse(char morse[]) {
  int k = 0;                   // spot we start at in the decoded array
  int size = getLength(morse); // creates variable size, is equal to the length
                               // of the more char array
  char *temp = new char[1]; // temp array, equal to morse array in size (might
                            // need to change that? does null data get used when
                            // using to assign another array?)
  char *decoded =
      new char[255]; // creates the array for the plaintext decoded message.
  decoded = S[0];
  temp = S[0];
  for (int i = 0; i < size;
       i++) { // top for loop, runs through all of morse code message
    if (morse[i] = '.') {
      *temp = strcat_s(temp, 1, "."); // sets temp equal to temp plus the next
                                      // character in the morse code char array
    } else {
      *temp = strcat_s(temp, 1, "-");
    }
    // or *temp = strcat_s(temp, 1, morse[i]) lol
    for (int j = 0; j < 26;
         j++) { // second for loop, runs through morse code library and compares
      if (temp[0] == ((*(*M[j]))) ||
          (*Mstart[j])) { // if the temp array is equal to part of that library
        decoded[k] = *B[j]; // assign plaintext version of that morse character
                            // to decoded array(why no *operator? Throws error)
        k++;           // move to the next spot in the decoded array
        delete[] temp; // delete temp
        char *temp =
            new char[1]; // recreate temp, needs to be empty so it can be the
                         // next morse character in our morse array
        temp = S[0];
      } else if (*temp == MS[0]) { // if temp equals morse for space
        decoded[k] = *S[0];        // assign space to decoded array
        k++;                       // move to next spot of k
        delete[] temp;             // delete temp
        char *temp = new char[1];  // recreate temp
        temp = S[0];
      } else { // if none of this is true we need to add another character of
               // the morse array, but nothing else needs to happen
      }
    }
  }

  int l = 0;

  return decoded;
  delete[] decoded;
  delete[] temp;
}
int main() {
  cout << *M[0][2] << endl;
  system("PAUSE");
  decryptMorse("-... ");
  system("PAUSE");
  return 0;
}
