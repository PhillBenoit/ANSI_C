/*
Phillip Benoit
CIS 279
Fall 2017
*/

#include <stdio.h>
#include <stdlib.h>
#include "Ex6.h"
#include "Input.h"

#define INPUT_QUESTION "Please input an unsigned short int in hex notation: (ex 1a2f)"
#define STRING_SIZE sizeof(unsigned short) * 2

//method requested by the book
//works by isolating the desired digits using &
//then bit shifts them to get them to their appropriate location
//finally it combines them with | for return
unsigned short swap_bytes(unsigned short i) {
	return ((i & 0x00FF) << 8) | ((i & 0xFF00) >> 8);
}

void ex6() {
	
	//variable for user input
	char user_input[STRING_SIZE + 1];

	//get user input
	getString(INPUT_QUESTION, user_input, STRING_SIZE);
	
	//convert user input from string
	unsigned short test_value = (unsigned short)strtol(user_input, NULL, 16);

	//displays value found
	printf("   The found value is: %04hx\n", test_value);

	//uses conversion method
	unsigned short result = swap_bytes(test_value);

	//displays the result
	printf("The swapped result is: %04hx\n\n", result);

	pause();
}
