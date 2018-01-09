/*
Phillip Benoit
CIS 279
Fall 2017
*/

//includes
#include "Ex9.h"
#include <stdio.h>

void ex9() {
	//arrays and their size
	int size_of_array = 4;
	double a[] = { 1, 2, 3, 4 };
	double b[] = { 1, 1, 1, 1 };

	//display arrays
	printf("First array: ");
	print_array(a, size_of_array);
	printf("\nSecond array: ");
	print_array(b, size_of_array);
	
	//display total of formula
	printf("\n\nTotal: %f\n\n", inner_product(a, b, size_of_array));
}

//used to print out the contents of an array
void print_array(const double *array, int length) {
	int end = array + length;
	for (array; array < end; array++)
		printf("%f ", *array);
}

//method requested by the book
double inner_product(const double * a, const double * b, int n)
{
	//total initalized to 0 for +=
	double total = 0.0;
	
	//point past end of array to stop the loop
	int end = a + n;

	//formula provided by book
	while (a < end) {
		total += *a * *b;
		a++;
		b++;
	}
	
	//return total
	return total;
}