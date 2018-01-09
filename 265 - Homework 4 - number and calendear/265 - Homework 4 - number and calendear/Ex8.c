/*
Phillip Benoit
CIS 279
Fall 2017
*/

//constants
#define DAYS_QUESTION "How many days are in the month?"
#define DAYS_MIN 28
#define DAYS_MAX 31

#define DAY_OF_THE_WEEK_QUESTION "What day of the week does it start on? (1 = Sunday, 7 = Saturday)"
#define DAY_OF_TTHE_WEEK_MIN 1
#define DAY_OF_THE_WEEK_MAX 7

#define HEADER " Sun Mon Tue Wed Thu Fri Sat"

//includes
#include "Input.h"
#include "Ex8.h"
#include <stdio.h>
#include <stdlib.h>

void ex8() {
	//get input
	int days = getInt(DAYS_QUESTION, DAYS_MIN, DAYS_MAX);
	int day_of_the_week_counter = getInt(DAY_OF_THE_WEEK_QUESTION,
		DAY_OF_TTHE_WEEK_MIN, DAY_OF_THE_WEEK_MAX);
	
	//start with a blank string for printing out leading blank days
	char day_string[3] = { ' ', ' ', '\0' };
	
	//diplay header with day of the week labels
	printf("%s\n", HEADER);

	//display leading blank days
	for (int leading_blank = 1;
		leading_blank < day_of_the_week_counter;
		leading_blank++)
		printCell(day_string);
	
	//loop for displaying days
	for (int day = 1; day < days + 1; day++) {
		
		//convert the day number to a string
		itoa(day, day_string, 10);
		
		//display the day
		printCell(day_string);
		
		//forking logic to reset saturday to sunday
		if (day_of_the_week_counter == 7) {
			day_of_the_week_counter = 1;
			printf("\n");
		//increase day of the week
		} else day_of_the_week_counter++;
	}
	//complete line if needed
	if (day_of_the_week_counter != 1) printf("\n");
	
	//extra visual space
	printf("\n");
}

//displays a single 4 column cell
void printCell(char *cell) {
	printf("%4s", cell);
}