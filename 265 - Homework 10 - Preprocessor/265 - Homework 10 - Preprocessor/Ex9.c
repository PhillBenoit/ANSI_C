/*
Phillip Benoit
CIS 279
Fall 2017
*/

#include "Ex9.h"
#include "Input.h"
#include <math.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


//pauses program between commands
void pause() {
	printf("---Press [enter] or [return] to continue---\n");
	getchar();
}

//method for check macro
void chk() {
	int x, y, n;
	x = getInt(FIRST, NUMBER_MIN, NUMBER_MAX);
	y = getInt(SECOND, NUMBER_MIN, NUMBER_MAX);
	n = getInt(UPPER, NUMBER_MIN, NUMBER_MAX);
	printf("The result is: %d\n\n", CHECK(x, y, n));
	pause();
}

//method for median macro
void med() {
	int x, y, z;
	x = getInt(FIRST, NUMBER_MIN, NUMBER_MAX);
	y = getInt(SECOND, NUMBER_MIN, NUMBER_MAX);
	z = getInt(THIRD, NUMBER_MIN, NUMBER_MAX);
	printf("The result is: %d\n\n", MEDIAN(x, y, z));
	pause();
}

//method for polynomial macro
void ply() {
	int x;
	//display polynomial before getting input
	printf("%s\n", PLY_STRING);
	x = getInt(FIRST, NUMBER_MIN, NUMBER_MAX);
	printf("The result is: %.0f\n\n", POLYNOMIAL(x));
	pause();
}


//display the menu
void printMenu() {
	printf("*********************************************************\n");
	printf("*                    -- Ex9 Menu --                     *\n");
	printf("*                                                       *\n");
	printf("*        (c) Check to see if x and y are both           *\n");
	printf("*            between 0 and n - 1                        *\n");
	printf("*                                                       *\n");
	printf("*        (m) Find the median of x, y, and z             *\n");
	printf("*                                                       *\n");
	printf("*        (p) Calculate a polynomial                     *\n");
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
		case 'c':
			chk();
			repeat = false;
			break;
		case 'm':
			med();
			repeat = false;
			break;
		case 'p':
			ply();
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
void ex9() {
	char quit;
	//loops while return character is not q for quit
	do { quit = menu(); } while (quit != 'q');
}
