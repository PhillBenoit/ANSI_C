/*
Phillip Benoit
CIS 279
Fall 2017
*/

#include "Input.h"

//constants
#define TAX_RATE 0.05f
#define MIN_AMOUNT 1.0f
#define MAX_AMOUNT 10000.0f

void ex4() {
	double amount = 0.0;
	//get double would not return a double so a pointer is passed instead
	getDouble("Enter an amount between 1.00 and 10000.00", MIN_AMOUNT, MAX_AMOUNT, &amount);
	
	//prints tax rate and total
	printf("Total with %.0f%% tax applied: $%.2f\n",
		TAX_RATE * 100,
		amount * (1 + TAX_RATE));
}