/*
Phillip Benoit
CIS 279
Fall 2017
*/

//input constants
#define INPUT_QUESTION "Please input some text: (max 20 characters, 4 characters ends input)"
#define INPUT_MAX 21

//string length to end looping
#define END_LOOP_LENGTH 4

#include "Ex1.h"
#include "Input.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
//#include <ctype.h> used for tolower

void ex1() {
	//variable allocated with maximum length
	char *input = malloc(INPUT_MAX * sizeof(char)),
		*lowest = malloc(INPUT_MAX * sizeof(char)),
		*highest = malloc(INPUT_MAX * sizeof(char));
	
	//used to store data used in logic forking
	int compare = 0,
		input_length;
	
	//initalize highest string with lowest value
	highest[0] = '\0';

	//initalize lowest string with highest value
	for (int index = 0; index < INPUT_MAX - 1; index++) lowest[index] = 'z';
	lowest[INPUT_MAX - 1] = '\0';
	
	do {
		//get input
		getWord(INPUT_QUESTION, input, INPUT_MAX - 1);
		input_length = strlen(input);

		//code for converting to lower case not used
		//for (int index = 0; index < input_length; index++)
			//input[index] = tolower(input[index]);

		//set to lowest if lower
		compare = strcmp(input, lowest);
		if (compare < 0) strcpy(lowest, input);

		//set to highest if higher
		compare = strcmp(input, highest);
		if (compare > 0) strcpy(highest, input);

	//loop while lengh of input isn't 4
	} while (input_length != END_LOOP_LENGTH);

	//results
	printf("\nString with the lowest value: %s\n", lowest);
	printf("String with the highest value: %s\n\n", highest);
	
	//free buffers
	free(input);
	free(lowest);
	free(highest);
}
