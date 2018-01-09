/*
Phillip Benoit
CIS 279
Fall 2017
*/

//Constants for input
#define INPUT_QUESTION "Please enter an income between 0.1 and 500000:"
#define INPUT_MIN 0.01
#define INPUT_MAX 500000.0

//defines number of tax brackets to establish arrays and
//provide a max number for running the bracket calulation loop
#define NUMBER_OF_TAX_BRACKETS 6

//minimum income for each tax bracket
const int TAX_BRACKET_MIN[NUMBER_OF_TAX_BRACKETS] = {0, 750, 2250, 3750, 5250, 7000};

//minimum amount each bracket must pay
const double BASE_TAX[NUMBER_OF_TAX_BRACKETS] = {0, 7.5, 37.5, 82.5, 142.5, 230.0};

#include "Ex5.h"
#include "Input.h"
#include <stdio.h>

void ex5() {
	double income = 0.0;
	
	//get income
	getDouble(INPUT_QUESTION, INPUT_MIN, INPUT_MAX, &income);
	
	//get and print the amount of taxes owed
	printf("The amount of tax on $%.2f is $%.2f\n\n", income, getTax(income));
}

//income is passed in to calcualte the amount owed in taxes
double getTax(double income) {
	//used to calculate tax rate and step through the tax brackets
	int index = 0;
	
	//increases index until max brackets is reached or income is below the next minimum
	for (index;
		index < NUMBER_OF_TAX_BRACKETS - 1 && income > TAX_BRACKET_MIN[index + 1];
		index++);
	
	//Calculates tax rate
	double tax_rate = (index+1) / 100.0;
	
	//Calculates taxable income based on bracket minimum
	double taxable_income = income - TAX_BRACKET_MIN[index];
	
	//Returns the total calcuated amount owed
	return BASE_TAX[index] + (taxable_income * tax_rate);
}
