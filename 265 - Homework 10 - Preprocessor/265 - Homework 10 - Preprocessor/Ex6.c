/*
Phillip Benoit
CIS 279
Fall 2017
*/

#include <stdio.h>
#include <math.h>
#include "Ex9.h"
#include "Ex6.h"
#include "Input.h"

void ex6() {
	//get input
	double x, y;
	getDouble(FIRST, SIX_MIN, SIX_MAX, &x);
	getDouble(SECOND, SIX_MIN, SIX_MAX, &y);

	//display result
	DISP(sqrt, x);
	DISP2(pow, x, y);

	printf("\n");
	pause();
}
