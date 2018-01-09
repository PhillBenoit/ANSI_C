/*
Phillip Benoit
CIS 279
Fall 2017
*/
#ifndef EX9_H_
#define EX9_H_

//min 0 because check macro must have positive n
#define NUMBER_MIN 0

//max 58 because 59 gives polynomial macro a return outside int bounds
#define NUMBER_MAX 58

//strings for display
#define MENU_INPUT_QUESTION "Please make a selection:"
#define MENU_INPUT_ERROR "Selection not recognized"
#define EXIT_QUESTION "Are you sure you want to quit? (y or n)"
#define FIRST "Please enter a number:"
#define SECOND "Please enter the second number:"
#define THIRD "Please enter the third number:"
#define UPPER "Please enter the upper limit for checking:"
#define PLY_STRING "3x^5 + 2x^4 - 5x^3 - x^2 + 7x - 6"

//calculate polynomial
#define POLYNOMIAL(x) ((3*pow(x, 5)) + (2*pow(x, 4)) - (5*pow(x, 3)) - (pow(x, 2)) + (7*x) - 6)

//check to see if x and y are between 0 and n - 1
#define CHECK(x, y, n) (x >= 0 && x <= --n && y >= 0 && y <= n)

//find median by adding all 3 and subtracting min and max
#define MEDIAN(x, y, z) ((x+y+z)-MIN(x,y,z)-MAX(x,y,z))

//min of 2 numbers
#define MIN_2(a, b) ((a > b) ? b : a)

//min of 3 numbers
#define MIN(x, y, z) (MIN_2(x, MIN_2(y,z)))

//max of 2 numbers
#define MAX_2(a, b) ((a < b) ? b : a)

//max of 4 numbers
#define MAX(x, y, z) (MAX_2(x, MAX_2(y,z)))

void pause();
void ex9();

#endif
