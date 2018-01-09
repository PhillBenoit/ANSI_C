/*
Phillip Benoit
CIS 279
Fall 2017
*/

#define INPUT_QUESTION "Please input some text: (max 50 characters)"
#define INPUT_MAX 51
#define OUTPUT "The reverse is: "

#include "Ex1.h"
#include "Input.h"
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

void ex1() {
	char *input = malloc(INPUT_MAX * sizeof(char));
	getString(INPUT_QUESTION, input, INPUT_MAX - 1);
	int length = strlen(input);
	printf(OUTPUT);
	reverse_print(input, length);
	printf("\n\n");
	free(input);
}

void reverse_print(char *string, int length) {
	int end = string;
	for (string = string + length - 1; string >= end; string--)
		printf("%c", *string);
}
