/*
Phillip Benoit
CIS 279
Fall 2017
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Input.h"
#include "Student.h"
#include "StudentList.h"

//strings for display
#define MENU_INPUT_QUESTION "Please make a selection:"
#define MENU_INPUT_ERROR "Selection not recognized"
#define EXIT_QUESTION "Are you sure you want to quit? (y or n)"
#define ID_QUESTION "Please enter a student ID:"
#define ID_ERROR "Student not found"

//source file
#define FILE_NAME "student database.txt"

//max line length
#define LINE_BUFFER_SIZE 90

//min / max Student ID
#define ID_MIN 0
#define ID_MAX 999999

//pauses program between commands
void pause() {
	printf("---Press [enter] or [return] to continue---\n");
	getchar();
}

//search option
void student_option() {

	//get user input
	int user_input = getInt(ID_QUESTION, ID_MIN, ID_MAX);

	//atempt to find student by ID
	struct student *found_student = findStudent(user_input);

	//display student if found
	if (found_student != NULL) printStudent(*found_student);

	//display error if not found
	else printf("%s\n", ID_ERROR);

	//pause program
	pause();
}

//display all option
void display() {

	//display all students in the list
	printList();

	//pause program
	pause();
}

//count option
void count() {

	//get count of students per campus
	int * campus_count = countCampuses();

	//step through the array and display count for each campus
	for (int counter = 0; counter < NUMBER_OF_CAMPUSES; counter++)
		printf("%s: %d students\n", CAMPUS_STRING[counter], *(campus_count + counter));

	//pause program
	pause();
}

//display the menu
void printMenu() {
	printf("*********************************************************\n");
	printf("*                    -- Main Menu --                    *\n");
	printf("*                                                       *\n");
	printf("*     (d) display all students' records information     *\n");
	printf("*                                                       *\n");
	printf("*     (s) search and display a student's                *\n");
	printf("*         information by student ID                     *\n");
	printf("*                                                       *\n");
	printf("*     (c) provide a count of students per campus        *\n");
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
		case 'd':
			display();
			repeat = false;
			break;
		case 's':
			student_option();
			repeat = false;
			break;
		case 'c':
			count();
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

//populate list from file
void populateList() {
	
	//holds student to add to list
	struct student s;

	//holds deliniated values from the file
	char *args;

	//line of text from file
	char line_of_text[LINE_BUFFER_SIZE];

	//delimiter between words
	const char delim[2] = ",";

	//open file for reading
	FILE *input_file;
	input_file = fopen(FILE_NAME, "r");

	//forking logic to detect errors in opening file
	if (input_file == NULL) printf("Error opening file: %s\n", FILE_NAME);
	else {

		//loops through each line of text
		while (fgets(line_of_text, LINE_BUFFER_SIZE, input_file) != NULL) {

			//parse words in line of text
			args = strtok(line_of_text, delim);

			//assigns ID based on INT value of string read from file
			s.id = atoi(args);

			//get next word
			args = strtok(NULL, delim);

			//assigns name as a string
			strcpy(s.name, args);

			//get next word
			args = strtok(NULL, delim);

			//assigns major using an enumerated value
			s.major = enumerateMajor(args);

			//get next word
			args = strtok(NULL, delim);
			
			//replaces end of line character if it's at the end of the string
			*(args + strlen(args) - 1) =
				(*(args + strlen(args) - 1) == '\n') ?
				'\0' :
				*(args + strlen(args) - 1);
			
			//assigns campus using an enumerated value
			s.campus = enumerateCampus(args);

			//adds student to the list as long as major and campus are both valid
			if (s.campus != Campus_Not_Found && s.major != Major_Not_Found) addStudent(s);

			//error message
			else printf("< %s > not added because enumeration failed\n", s.name);
		}

		//close file
		fclose(input_file);
	}
}

//entry point for program
int main() {
	
	//populate list from file
	populateList();

	char quit;
	//loops while return character is not q for quit
	do { quit = menu(); } while (quit != 'q');

	return 0;
}
