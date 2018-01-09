/*
Phillip Benoit
CIS 279
Fall 2017
*/

#include <stdio.h>
#include "Ex1.h"
#include "Ex8.h"

int main() {

	printf("--------------------< EX 1 >--------------------\n\n");
	ex1();

	printf("\n--------------------< EX 8 >--------------------\n\n");
	ex8();

	printf("---Press [enter] or [return] to end program---\n");
	while (getchar() != '\n');
	getchar();
	return 0;
}