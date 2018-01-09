/*
Phillip Benoit
CIS 279
Fall 2017
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "Input.h"

//string for input
#define INPUT_QUESTION "Please input a word for the list: (blank entry will end the loop)"

//max length
#define MAX_WORD_SIZE 20
#define MAX_LIST_SIZE 50

//input method defined by original file
int read_line(char str[], int n)
{
	int ch, i = 0;
	//added displaying input question to the method
	printf("%s\n", INPUT_QUESTION);
	while ((ch = getchar()) != '\n')
		if (i < n)
			str[i++] = ch;
	str[i] = '\0';
	return i;
}

//entry point for program
int main() {
	//counter for number of elements in the list
	int list_size = 0;
	
	//buffer for input
	char input[MAX_WORD_SIZE + 1];
	
	//list of input words
	char *list[MAX_LIST_SIZE];

	//loop for input runs while input isn't blank
	while (list_size < MAX_LIST_SIZE && read_line(input, MAX_WORD_SIZE) > 0) {
		
		//stores the length of the input string
		int input_length = strlen(input);
		
		//converts input to lower case
		for (int index = 0; index < input_length; index++)
			input[index] = tolower(input[index]);
		
		//stores the array position for the sorted element and increases the list size counter
		int sorted_position = list_size++;
		
		//searches from the botom up for the input's proper position
		while (sorted_position > 0 && strcmp(input, list[sorted_position - 1]) < 0)
			//moves items down the list to make room for the new input
			list[sorted_position--] = list[sorted_position - 1];
		
		//assigns space and copies input to the proper location
		list[sorted_position] = malloc((input_length + 1) * sizeof(char));
		strcpy(list[sorted_position], input);
	}

	//displays sorted list
	printf("The sorted list is:\n");
	for (int step = 0; step < list_size; step++) printf("%s\n", list[step]);

	//free memory and end program
	for (int step = 0; step < list_size; step++) free(list[step]);
	printf("---Press [enter] or [return] to continue---\n");
	getchar();
	return 0;
}
