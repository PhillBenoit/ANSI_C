/*
Phillip Benoit
CIS 279
Fall 2017
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "Input.h"

//strings for display
#define MENU_INPUT_QUESTION "Please make a selection:"
#define MENU_INPUT_ERROR "Selection not recognized"
#define EXIT_QUESTION "Are you sure you want to quit? (y or n)"
#define SEARCH_QUESTION "Please enter a word to search for:"
#define LINE_QUESTION "How many lines would you like to display?"
#define APPEND_QUESTION "Please input text to append to the file:"

//source file
#define FILE_NAME "CIS265.txt"

//max line length
#define LINE_BUFFER_SIZE 120

//pauses program between commands
void pause() {
	printf("---Press [enter] or [return] to continue---\n");
	getchar();
}

//search option
//searches file for a word, displays them in braces and counts occurances
void search() {
	
	//line of text from file
	char line_of_text[LINE_BUFFER_SIZE];

	//delimiter between words
	const char delim[2] = " ";

	//string to search for
	char user_input[LINE_BUFFER_SIZE];
	
	//open file for reading
	FILE *input_file;
	input_file = fopen(FILE_NAME, "r");
	
	//forking logic to detect errors in opening file
	if (input_file == NULL) printf("Error opening file: %s\n", FILE_NAME);
	else {

		//get string to search for
		getWord(SEARCH_QUESTION, user_input, LINE_BUFFER_SIZE - 1);

		//initalize number of occurances
		int occurrences = 0;

		//loops through each line of text
		while (fgets(line_of_text, LINE_BUFFER_SIZE, input_file) != NULL) {
			
			//parse words in line of text
			char *args;
			args = strtok(line_of_text, delim);

			//steps through words
			while (args != NULL) {
				
				//forking logic for searched word
				if (strcmp(args, user_input) == 0) {
					printf(" [%s]", args);
					occurrences++;
				
				//default printing for unmached strings
				} else printf(" %s", args);
				
				//get next word
				args = strtok(NULL, delim);
			}
			//free buffer
			free(args);
		}
		//display occurances count
		printf("\nNumber of occurrences of the word \"%s\" is %d\n\n",
			user_input, occurrences);
		
		//close file
		fclose(input_file);
	}
	//pause program
	pause();
}

//line display option
//counts the number of lines in the file then prompts for number to display
void lines() {
	
	//line of text from file
	char line_of_text[LINE_BUFFER_SIZE];

	//open file for reading
	FILE *input_file;
	input_file = fopen(FILE_NAME, "r");
	
	//forking logic to handle errors opening the file
	if (input_file == NULL) printf("Error opening file: %s\n", FILE_NAME);
	else {
	
		//counter for number of lines in the file
		int line_counter = 0;

		//count number of lines in the file
		while (fgets(line_of_text, LINE_BUFFER_SIZE, input_file) != NULL) line_counter++;
		
		//reset the reader
		rewind(input_file);

		//display number of lines
		printf("The file has %d lines to display.\n", line_counter);
		
		//get number lines to display based on max of number of line in the file
		int lines = getInt(LINE_QUESTION, 1, line_counter);
		
		//display lines
		for (int x = 0; x < lines; x++) {
			fgets(line_of_text, LINE_BUFFER_SIZE, input_file);
			printf("%s", line_of_text);
		}

		//extra whitespace for visual purposes
		printf("\n");
		
		//close the file
		fclose(input_file);
	}
	//pause program
	pause();
}

//append option
//appends user input to the file
void append() {
	
	//user input
	char user_input[LINE_BUFFER_SIZE];

	//open file for appending
	FILE *input_file;
	input_file = fopen(FILE_NAME, "a");
	
	//forking logic to catch errors in opening the file
	if (input_file == NULL) printf("Error opening file: %s\n", FILE_NAME);
	else {
		
		//get input
		getString(APPEND_QUESTION, user_input, LINE_BUFFER_SIZE - 1);
		
		//write input
		fprintf(input_file, "%s\n", user_input);
		
		//close file
		fclose(input_file);
	}
	//pause program
	pause();
}

//display the menu
void printMenu() {
	printf("*********************************************************\n");
	printf("*                    -- Main Menu --                    *\n");
	printf("*                                                       *\n");
	printf("*        (s) Search for a word                          *\n");
	printf("*                                                       *\n");
	printf("*        (l) Display lines of text                      *\n");
	printf("*                                                       *\n");
	printf("*        (a) Append text to file                        *\n");
	printf("*                                                       *\n");
	printf("*        (q) Quit                                       *\n");
	printf("*                                                       *\n");
	printf("*********************************************************\n");
}

//menu logic
char menu() {
	
	//variable to hold user input
	char *input = malloc(2 * sizeof(char));
	
	//indicator for repeating the menu input in case of input error
	bool repeat = true;
	
	//display menu
	printMenu();
	
	do {
		//get selection
		getWord(MENU_INPUT_QUESTION, input, 1);
		
		//forking logic for selection
		switch (input[0]) {
		
		//quit option
		case 'q':
			//ask if the user wants to quit
			repeat = !getYN(EXIT_QUESTION);
			//display menu again if user cancels
			if (repeat) printMenu();
			break;
		
		//other options
		case 's':
			search();
			repeat = false;
			break;
		case 'l':
			lines();
			repeat = false;
			break;
		case 'a':
			append();
			repeat = false;
			break;
		
		//default option in case of input error
		default:
			printf("%s\n", MENU_INPUT_ERROR);
		}
	//loops while input is not recognized or quit was canceled
	} while (repeat);
	
	//declare return character, free input buffer and return to main
	char return_char = input[0];
	free(input);
	return return_char;
}

//entry point for program
int main() {
	char quit;
	//loops while return character is not q for quit
	do {quit = menu();} while (quit != 'q');
	return 0;
}
