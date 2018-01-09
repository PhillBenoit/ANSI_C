/*
Phillip Benoit
CIS 279
Fall 2017
*/

#include <stdio.h>
#include "Ex9.h"
#include "Ex1.h"

int main() {

	printf("--------------------< EX 9 >--------------------\n\n");
	ex9();

	printf("\n--------------------< EX 1 >--------------------\n\n");
	ex1();

	printf("---Press [enter] or [return] to end program---\n");
	while (getchar() != '\n');
	getchar();
	return 0;
}