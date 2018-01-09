/*
Phillip Benoit
CIS 265
Fall 2017
*/

#define LINE_BUFFER_SIZE 30
#define NUMBER_OF_DIGITS 10

#include <stdio.h>
#include <stdbool.h>

//tests a character for numberical value
bool isDigit(char c) {
	if (c <= 57 && c >= 48) return true;
	return false;
}

//processes a single line of text to find and print a phone number
void printNumber(char *line_of_text) {
	
	//variables to hold found numbers and a single test character
	char number[NUMBER_OF_DIGITS], test_char = *line_of_text;
	
	//counters for the number of found numbers and the position
	//of the test char in the line of text
	int number_counter = 0, text_counter = 0;
	
	//loops through the line of text until the end or all digits are found
	while (test_char != '\0' && number_counter < NUMBER_OF_DIGITS) {
		
		//saves character if it is a number
		if (isDigit(test_char)) number[number_counter++] = test_char;
		
		//gets the next character in the line of text
		test_char = *(line_of_text + ++text_counter);
	}

	//prints the phone number if the correct number of digits are found
	if (number_counter == NUMBER_OF_DIGITS)
		printf("(%c%c%c) %c%c%c-%c%c%c%c\n", number[0], number[1], number[2],
			number[3], number[4], number[5], number[6], number[7],
			number[8], number[9]);
}

//entry point for the program
int main(int argc, char *argv[]) {

	//line of text from file
	char line_of_text[LINE_BUFFER_SIZE];

	//file for reading
	FILE *input_file = NULL;

	//check for file name argument before opening file
	if (argc > 1) input_file = fopen(argv[1], "r");

	//forking logic to detect errors in opening file
	if (input_file == NULL) printf("\nError opening file\n");
	else {

		//loops through each line of text
		while (fgets(line_of_text, LINE_BUFFER_SIZE, input_file) != NULL)
			printNumber(line_of_text);

		//close file
		fclose(input_file);
	}

	return 0;
}