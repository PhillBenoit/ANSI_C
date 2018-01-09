/*
Phillip Benoit
CIS 279
Fall 2017
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

//question is the input question
//return_string is the value that will stay stored in memory
//max is the max size of the return string
void getWord(char *question, char *return_string, unsigned max) {
	//large buffer for input
	char *buffer = malloc(255 * sizeof(char));

	printf("%s\n", question);
	//flushing appears to be necessary for the Eclipse terminal emulator
	fflush(stdout);
	scanf("%s", buffer);

	//runs loop while input is too long
	while (strlen(buffer) > max) {
		printf("Input not recognized.  Please use shorter input."
			" (maximum %d characters)\n", max);
		printf("%s\n", question);
		fflush(stdout);
		scanf("%s", buffer);
	}

	//confimation message
	printf("You entered: %s\n\n", buffer);
	
	//store the input
	strcpy(return_string, buffer);
	
	//free input buffer
	free(buffer);
}

void getString(char *question, char *return_string, unsigned max) {
	
	//large buffer for input
	char *buffer = malloc(255 * sizeof(char));
	
	//test to see if loop needs to be repeated
	bool repeat = false;

	do {
		//print question
		printf("%s\n", question);
		
		//get input
		fgets(buffer, 255, stdin);
		
		//remove new line character from input
		buffer[strlen(buffer) - 1] = '\0';
		
		//test to see if repeat is necessary
		repeat = strlen(buffer) > max;

		//print error message if input needs to be repeated
		if (repeat) printf("Input not recognized.  Please use shorter input."
			" (maximum %d characters)\n", max);
	} while (repeat);

	//confimation message
	printf("You entered: %s\n\n", buffer);

	//store the input
	strcpy(return_string, buffer);

	//free input buffer
	free(buffer);
}


//calls getWord for input then converts it for return
int intLoop(char *question) {
	//invokes getWord with a 9 max length. smaller than the
	//int max of over 2 billion but good enough for our purposes
	int stringLength = 10;
	char *stringInt = malloc(stringLength * sizeof(char));
	getWord(question, stringInt, stringLength - 1);

	int returnInt = atoi(stringInt);
	free(stringInt);
	return returnInt;
}

//invokes intLoop while the integer is out of bounds for specifications
int getInt(char *question, int min, int max) {
	int returnInt = intLoop(question);
	while (returnInt < min || returnInt > max) {
		printf("Input (%d) out of bounds.  Please use a number between. (%d) and (%d)\n", returnInt, min, max);
		returnInt = intLoop(question);
	}
	return returnInt;
}

//calls getWord for input then converts it for return
double doubleLoop(char *question) {
	int stringLength = 12;
	char *stringDouble = malloc(stringLength * sizeof(char));
	getWord(question, stringDouble, stringLength - 1);

	double returnDouble = atof(stringDouble);
	free(stringDouble);
	return returnDouble;
}

//invokes doubleLoop while the double is out of bounds for specifications
void getDouble(char *question, double min, double max, double *value) {
	double returnDouble = doubleLoop(question);
	while (returnDouble < min || returnDouble > max) {
		printf("Input (%f) out of bounds.\nPlease use a number between. (%f) and (%f)\n", returnDouble, min, max);
		returnDouble = doubleLoop(question);
	}
	//would not return a double to other packages so a pointer is passed iansted
	*value = returnDouble;
}