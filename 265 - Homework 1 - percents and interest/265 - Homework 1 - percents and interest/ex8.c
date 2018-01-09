/*
Phillip Benoit
CIS 279
Fall 2017
*/

#include "Input.h"

//constants
#define AMOUNT_MIN 1.0f
#define AMOUNT_MAX 500000.0f
#define RATE_MIN 0.01f
#define RATE_MAX 30.0f
#define PAYMENT_MIN 1.0f
#define PAYMENT_MAX (AMOUNT_MAX / 10)
#define NUMBER_OF_PAYMENTS 3

void ex8() {
	double balance = 0.0f, interest_rate = 0.0f, payment = 0.0f;

	getDouble("Please enter a loan amount: (1 - 500000)",
		AMOUNT_MIN, AMOUNT_MAX, &balance);

	getDouble("Please enter the yearly interest rate: (in percent 0.01 - 30)",
		RATE_MIN, RATE_MAX, &interest_rate);
	//converts to the actual monthly rate
	interest_rate = 1 + (interest_rate / 1200);

	getDouble("Please enter the monthly payment: (1 - 50000)",
		PAYMENT_MIN, PAYMENT_MAX, &payment);

	for (int month_counter = 0;
		//loop stops if requisite number of months is reached
		//or if the balance is 0
		month_counter < NUMBER_OF_PAYMENTS && balance > 0;
		month_counter++) {
		
		//sets balance to 0 if payment is greater than the remaining balance
		if (balance < payment) balance = 0;
		//calculation used by the book for remaining balance
		else balance = (balance * interest_rate) - payment;
		//displays remaning balance
		printf("Balance after month %d is: $%.2f\n", month_counter+1, balance);
	}
	//add blank line after program execution
	printf("\n");
}