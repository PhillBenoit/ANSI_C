/*
Phillip Benoit
CIS 279
Fall 2017
*/

#include <stdio.h>
#include "Ex3.h"
#include "Ex4.h"

int main() {

	printf("--------------------< EX 3 >--------------------\n\n");
	ex3();

	printf("\n--------------------< EX 4 >--------------------\n\n");
	ex4();

	printf("---Press [enter] or [return] to end program---\n");
	while (getchar() != '\n');
	getchar();
	return 0;
}