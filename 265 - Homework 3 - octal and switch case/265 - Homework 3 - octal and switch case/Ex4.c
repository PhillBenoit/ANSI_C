/*
Phillip Benoit
CIS 279
Fall 2017
*/

//Constants
#define INPUT_QUESTION "Please enter a number between 0 and 32767:"
#define INPUT_MIN 0
#define INPUT_MAX 32767

#include "Input.h"
#include "Ex4.h"
#include <stdio.h>

void ex4() {
	//get input
	int input_number = getInt(INPUT_QUESTION, INPUT_MIN, INPUT_MAX);
	
	//display as octal with leading 0s
	printf("%d converted to octal is %.5o\n\n", input_number, input_number);
}