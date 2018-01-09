/*
Phillip Benoit
CIS 279
Fall 2017
*/

#include <stdio.h>
#include "Ex4.h"
#include "Ex5.h"

int main() {

	printf("--------------------< EX 4 >--------------------\n\n");
	ex4();

	printf("\n--------------------< EX 5 >--------------------\n\n");
	ex5();

	printf("---Press [enter] or [return] to end program---\n");
	while (getchar() != '\n');
	getchar();
	return 0;
}