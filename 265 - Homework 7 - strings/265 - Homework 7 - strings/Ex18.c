/*
Phillip Benoit
CIS 279
Fall 2017
*/

//input question
#define INPUT_QUESTION "Please input a date: (mm/dd/yyyy)"

//months
#define JAN "January"
#define FEB "February"
#define MAR "March"
#define APR "April"
#define MAY "May"
#define JUN "June"
#define JUL "July"
#define AUG "August"
#define SEP "September"
#define OCT "October"
#define NOV "November"
#define DEC "December"

//bad input return string
#define BAD_INPUT "Month not recognized"

//array for return as requested by the book
char * MONTHS[] = {BAD_INPUT, JAN, FEB, MAR, APR, MAY,
					JUN, JUL, AUG, SEP, OCT, NOV, DEC};


#include "Ex18.h"
#include <stdio.h>

void ex18() {
	//declare and initalize
	int month = 0, day = 0, year = 0;
	
	//display input question
	printf("\n%s\n", INPUT_QUESTION);
	
	//get input
	scanf("%d/%d/%d", &month, &day, &year);
	
	//print results
	printf("\n%s %d, %d\n\n", monthToString(month), day, year);
}

//returns a string for the month based off of int input
char * monthToString(int month) {
		
	//prevents index from being out of bounds
	if (month < 0 || month > 12) month = 0;
	
	//return string value
	return MONTHS[month];
}