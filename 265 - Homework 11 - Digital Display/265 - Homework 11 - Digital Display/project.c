/*
Phillip Benoit
CIS 279
Fall 2017
*/

#include <stdio.h>
#include <string.h>
#include "Input.h"

//strings for input
#define INPUT_QUESTION "Please input digits to display: (up to 10)"
#define RESTART_QUESTION "Would you like to display more digits? (Y or N)"

//limits
#define MAX_DIGITS 10
#define MAX_INPUT 20
#define DIGIT_HEIGHT 3
#define DIGIT_WIDTH 4

//digits represented as strings
#define ZERO1 " _  "
#define ZERO2 "| | "
#define ZERO3 "|_| "

#define ONE1 "    "
#define ONE2 "  | "
#define ONE3 "  | "

#define TWO1 " _  "
#define TWO2 " _| "
#define TWO3 "|_  "

#define THREE1 " _  "
#define THREE2 " _| "
#define THREE3 " _| "

#define FOUR1 "    "
#define FOUR2 "|_| "
#define FOUR3 "  | "

#define FIVE1 " _  "
#define FIVE2 "|_  "
#define FIVE3 " _| "

#define SIX1 " _  "
#define SIX2 "|_  "
#define SIX3 "|_| "

#define SEVEN1 " _  "
#define SEVEN2 "  | "
#define SEVEN3 "  | "

#define EIGHT1 " _  "
#define EIGHT2 "|_| "
#define EIGHT3 "|_| "

#define NINE1 " _  "
#define NINE2 "|_| "
#define NINE3 " _| "

//number of digits defined as ascii
#define DIGITS_MAPPED 10

//numeric map to digit ascii lines
char *digit_map[DIGIT_HEIGHT][DIGITS_MAPPED] = {
	{ ZERO1, ONE1, TWO1, THREE1, FOUR1, FIVE1, SIX1, SEVEN1, EIGHT1, NINE1 },
	{ ZERO2, ONE2, TWO2, THREE2, FOUR2, FIVE2, SIX2, SEVEN2, EIGHT2, NINE2 },
	{ ZERO3, ONE3, TWO3, THREE3, FOUR3, FIVE3, SIX3, SEVEN3, EIGHT3, NINE3 },
};

//holds output
char digits[DIGIT_HEIGHT][(MAX_DIGITS*DIGIT_WIDTH)+1];

//method requested by the book
void clear_digits_array(void) {
	//fills possible end points with null characters
	for (int x = 0; x < DIGIT_HEIGHT; x++)
		for (int y = 0; y < MAX_DIGITS + 1; y++)
			digits[x][y*DIGIT_WIDTH] = '\0';
}

//method requested by the book
void process_digit(int digit, int position) {
	//coppies ascii mapped digit to output in its given position
	for (int row = 0; row < DIGIT_HEIGHT; row++)
		strcpy(&digits[row][position * 4], digit_map[row][digit]);
}

//method requested by the book
void print_digits_array(void) {
	//displays output
	for (int index = 0; index < DIGIT_HEIGHT; index++)
		printf("%s\n", &digits[index]);
}

//entry point for program
int main() {
	
	//buffer to hold user input
	char input[MAX_INPUT + 1];
	
	//main program loop
	do {
		//get user input
		getString(INPUT_QUESTION, &input, MAX_INPUT);
		
		//clear ourput array
		clear_digits_array();
		
		//Index for stepping through input and counter for the number of digits found
		int input_position = 0, digit_counter = 0;
		
		//loops until all input has been searched or 10 digits have been found
		while (digit_counter < MAX_DIGITS && input[input_position] != '\0') {

			//associates user input ascii with numberical value
			int digit = -1;
			switch (input[input_position]) {
			case '0': digit = 0; break;
			case '1': digit = 1; break;
			case '2': digit = 2; break;
			case '3': digit = 3; break;
			case '4': digit = 4; break;
			case '5': digit = 5; break;
			case '6': digit = 6; break;
			case '7': digit = 7; break;
			case '8': digit = 8; break;
			case '9': digit = 9; break;
			}
			
			//assign digit to output from input and increase the digit counter 
			//if a digit is found in the input position
			if (digit > -1) process_digit(digit, digit_counter++);
			
			//increase the input position counter
			input_position++;
		}

		//print output
		print_digits_array();

	//Loop program if the user decides to continue
	} while (getYN(RESTART_QUESTION));

	return 0;
}
