/*
Phillip Benoit
CIS 279
Fall 2017
*/

#include <stdio.h>
#include <stdlib.h>
#include "Input.h"
#include "Queue.h"

//strings for display
#define MENU_INPUT_QUESTION "Please make a selection:"
#define MENU_INPUT_ERROR "Selection not recognized"
#define EXIT_QUESTION "Are you sure you want to quit? (y or n)"
#define INT_INPUT_QUESTION "Please enter a number to add to the queue"

#define MIN_NUMBER -100
#define MAX_NUMBER 100

//pauses program between commands
void pause() {
	printf("---Press [enter] or [return] to continue---\n");
	getchar();
}

//first option, enqueue
void option1() {
	enqueue(getInt(INT_INPUT_QUESTION, MIN_NUMBER, MAX_NUMBER));
	printf("%d added to the the list.\n", peekBack());
	pause();
}

//second option, dequeue
void option2() {
	printf("%d removed from the list.\n", dequeue());
	pause();
}

//third option, peek at value in front
void option3() {
	printf("%d is the first item in the list.\n", peekFront());
	pause();
}

//fourth option, peek at value in back
void option4() {
	printf("%d is the last item in the list.\n", peekBack());
	pause();
}

//fifth option, display count
void option5() {
	printf("There are %d items in the list.\n", getCount());
	pause();
}

//sixth option, display the whole queue
void option6() {
	printList();
	pause();
}

//seventh option, poplate the list
void option7() {
	for (int step = 1; step < 6; step++)
		enqueue(step);
	//finished by diplaying the count and pausing
	option5();
}

//display the menu
void printMenu() {
	printf("*********************************************************\n");
	printf("*                    -- Main Menu --                    *\n");
	printf("*                                                       *\n");
	printf("*     (1) Add a number to the queue                     *\n");
	printf("*     (2) Remove the first integer in the queue         *\n");
	printf("*     (3) Display first item in the queue               *\n");
	printf("*     (4) Display last item in the queue                *\n");
	printf("*     (5) Display a count of integers in the queue      *\n");
	printf("*                                                       *\n");
	printf("*     (6) Display the whole queue                       *\n");
	printf("*                                                       *\n");
	printf("*     (7) Populate the list with 5 integers             *\n");
	printf("*                                                       *\n");
	printf("*     (q) Quit                                          *\n");
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
		case '1':
			option1();
			repeat = false;
			break;
		case '2':
			option2();
			repeat = false;
			break;
		case '3':
			option3();
			repeat = false;
			break;
		case '4':
			option4();
			repeat = false;
			break;
		case '5':
			option5();
			repeat = false;
			break;
		case '6':
			option6();
			repeat = false;
			break;
		case '7':
			option7();
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
	do { quit = menu(); } while (quit != 'q');

	return 0;
}
