/*
Phillip Benoit
CIS 279
Fall 2017
*/

//input constants
#define INPUT_QUESTION "Please input a number for x between 1 and 50"
#define INPUT_MIN 1
#define INPUT_MAX 50

//includes
#include "Ex6.h"
#include "Input.h"
#include <stdio.h>
#include <math.h>

//Pollynomial writtrn backwards in to the
//array so value in index matches x^index 
const int poly[] = {-6, 7, -1, -5, 2, 3};

//size of polly array
const int poly_size = sizeof(poly) / sizeof(int);

void ex6() {
	//prints pollynomial
	printf("%dx^%d", poly[poly_size - 1], poly_size - 1);
	for (int index = poly_size - 2; index > 1; index--)
		printf(" %c %dx^%d", sign(poly[index]), abs(poly[index]), index);
	printf(" %c %dx", sign(poly[1]), abs(poly[1]));
	printf(" %c %d\n", sign(poly[0]), abs(poly[0]));
	
	//get input
	int x = getInt(INPUT_QUESTION, INPUT_MIN, INPUT_MAX);
	
	//run calculation
	int total = calculatePoly(x);
	
	//print total
	printf("The total is: %d\n\n", total);
}

//retuns character based on positive / negative
char sign(int x) {
	if (x > -1) return '+';
	return '-';
}

int calculatePoly(int x)
{
	int total = 0;

	//calculates each term and adds to the total
	for (int index = poly_size - 1; index > -1; index--)
		total += poly[index] * pow(x, index);

	return total;
}
