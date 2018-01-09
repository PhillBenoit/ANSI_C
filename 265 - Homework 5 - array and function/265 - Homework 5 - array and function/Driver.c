/*
Phillip Benoit
CIS 279
Fall 2017
*/

#include <stdio.h>
#include "Ex7.h"
#include "Ex6.h"

int main() {

	printf("--------------------< EX 7 >--------------------\n\n");
	ex7();

	printf("\n--------------------< EX 6 >--------------------\n\n");
	ex6();

	printf("---Press [enter] or [return] to end program---\n");
	while (getchar() != '\n');
	getchar();
	return 0;
}