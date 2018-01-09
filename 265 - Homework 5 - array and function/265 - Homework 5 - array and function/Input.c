/*
Phillip Benoit
CIS 279
Fall 2017
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//question is the input question
//return_string is the value that will stay stored in memory
//max is the max size of the return string
void *getString(char *question, char *return_string, int max) {
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

	//explicitly use the last space for a null character
	if (strlen(buffer) == max) buffer[max] = '\0';
	
	//confimation message
	printf("You entered: %s\n\n", buffer);
	
	//store the input
	strcpy(return_string, buffer);
	
	//free input buffer
	free(buffer);
}

//calls getString for input then converts it for return
int intLoop(char *question) {
	//invokes getString with a 9 max length. smaller than the
	//int max of over 2 billion but good enough for our purposes
	int stringLength = 10;
	char *stringInt = malloc(stringLength * sizeof(char));
	getString(question, stringInt, stringLength - 1);

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

//calls getString for input then converts it for return
double doubleLoop(char *question) {
	int stringLength = 12;
	char *stringDouble = malloc(stringLength * sizeof(char));
	getString(question, stringDouble, stringLength - 1);

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