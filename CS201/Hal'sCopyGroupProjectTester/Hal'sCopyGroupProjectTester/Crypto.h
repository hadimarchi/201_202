#pragma once
#ifndef CRYTPO_H_INCLUDED
#define CRYPTO_H_INCLUDED

#include "stdafx.h"
#include <cstring>
#include <iostream>
#include <cstdlib>
using namespace std;	



char* B[26] = { "A","B","C","D","E","F","G","H","I","J","K","L","M",
"N","O","P","Q","R","S","T","U","V","W","X","Y","Z" };

char* M[26] = { ".- ", "-... ", "-.-. ", "-.. ", ". ", "..-. ", "--. ",
".... ", ".. ", ".--- ", "-.- ", ".-.. ", "-- ", "-. ", "--- ",
".--. ", "--.- ", ".-. ", "... ", "- ", "..- ", "...- ", ".-- ",
"-..- ", "-.-- ", "--.. " };
char* Mstart[26] = { " .- ", " -... ", " -.-. ", " -.. ", " . ", " ..-. ", " --. ",
" .... ", " .. ", " .--- ", " -.- ", " .-.. ", " -- ", " -. ", " --- ",
" .--. ", " --.- ", " .-. ", " ... ", " - ", " ..- ", " ...- ", " .-- ",
" -..- ", " -.-- ", " --.. " };
char* S[1] = { " " };
char* MS = new char[1]{ "   " };
int getLength(char temp[]);
char decryptMorse(char morse[]);

#endif