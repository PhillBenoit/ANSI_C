/*
Phillip Benoit
CIS 279
Fall 2017
*/

#include <stdio.h>
#include "Ex18.h"
#include "Ex1.h"

int main() {

	printf("\n--------------------< EX 1 >--------------------\n\n");
	ex1();

	printf("--------------------< EX 18 >--------------------\n\n");
	ex18();

	printf("---Press [enter] or [return] to end program---\n");
	while (getchar() != '\n');
	getchar();
	return 0;
}