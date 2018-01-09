/*
Phillip Benoit
CIS 279
Fall 2017
*/

#include <stdio.h>
#include <math.h>
#include "Ex2.h"
#include "Input.h"

#define INPUT_X "Please input x"
#define INPUT_Y "Please input y"

//does not seem to calculate negative values properly
#define MIN 1
#define MAX 20

//ratio for converting radinas to degrees
#define RAD_RATIO 180 / 3.14159265358979323846


void ex2() {

	//variables to hold values
	double x, y, r, theta, thetaDeg;

	//get user input
	getDouble(INPUT_X, MIN, MAX, &x);
	getDouble(INPUT_Y, MIN, MAX, &y);
	
	//calculate conversions
	r = sqrt( (x*x) + (y*y) );
	theta = atan(y / x);
	thetaDeg = theta * RAD_RATIO;

	//output results
	printf("r = %f\ntheta (radian) = %f\ntheta (degree) = %f\n",
		r, theta, thetaDeg);

	pause();
}
