/*
Phillip Benoit
CIS 279
Fall 2017
*/

#ifndef EX6_H_
#define EX6_H_

//min / max for input
#define SIX_MIN -100.0
#define SIX_MAX 100.0

//part a
#define DISP(f, x) (printf(#f "(%g) = %g\n", x, ##f(x)))

//part b
#define DISP2(f, x, y) (printf(#f "(%g, %g) = %g\n", x, y, ##f(x, y)))

void ex6();

#endif
