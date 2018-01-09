/*
Phillip Benoit
CIS 279
Fall 2017
*/

//constants
#define INPUT_QUESTION "Please enter a number up to 10000.0: (0 will end input loop)"
#define INPUT_MIN 0.0
#define INPUT_MAX 10000.0

//includes
#include "Input.h"
#include "Ex1.h"
#include <stdio.h>

void ex1() {
	//declare the two varibales needed
	double highest = 0.0, input = 0.0;
	
	//do loop used to execute code at least once
	do {
		
		//get input
		getDouble(INPUT_QUESTION, INPUT_MIN, INPUT_MAX, &input);
		
		//if input is greater, it is stored as highest value
		if (input > highest) highest = input;
	
	//run loop while input isn't 0
	} while (input > 0);
	
	//display results
	printf("The highest number entered was %g\n\n", highest);
}