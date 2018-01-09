/*
Phillip Benoit
CIS 279
Fall 2017
*/

//parts of the input question
#define INPUT_QUESTION_1 "Please input row"
#define INPUT_QUESTION_2 "integers separated by spaces"

//grid size is defined dynamically
//same code can be used on a grid of any size
#define GRID_SIZE 5

//includes
#include "Ex7.h"
#include <stdio.h>

void ex7() {
	
	//int used to hold input
	int input;
	
	//totals
	int row_total[GRID_SIZE];
	int column_total[GRID_SIZE];
	
	//initialize each array
	for (int index = 0; index < GRID_SIZE; index++) {
		row_total[index] = 0;
		column_total[index] = 0;
	}

	//loops through rows for input
	for (int row = 0; row < GRID_SIZE; row++) {
		printf("%s %d.  (%d %s):\n", INPUT_QUESTION_1, row + 1,
			GRID_SIZE, INPUT_QUESTION_2);
		
		//processes each integer input
		for (int column = 0; column < GRID_SIZE; column++) {
			scanf("%d", &input);

			//adds each integer to row total
			row_total[row] += input;
			
			//adds each integer to the column total
			column_total[column] += input;
		}
	}

	//prints totals
	printf("\nRow totals: ");
	printCells(row_total);
	printf("Column totals: ");
	printCells(column_total);
	printf("\n");
}

//prints the resuts of a single array
void printCells(int cell[]) {
	for (int index = 0; index < GRID_SIZE; index++) printf("%d ", cell[index]);
	printf("\n");
}
