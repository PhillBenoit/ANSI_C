/*
Phillip Benoit
CIS 265
Fall 2017
*/

//max size for a single line of text
#define LINE_BUFFER_SIZE 120

#include <stdio.h>

//line of text from file
char line_of_text[LINE_BUFFER_SIZE];

//file for reading
FILE *input_file;

//prints the contents of the file passed to it
void printFile(char *fileName) {

	//open file for reading
	input_file = fopen(fileName, "r");

	//forking logic to detect errors in opening file
	if (input_file == NULL) printf("\nError opening file: %s\n", fileName);
	else {

		//loops through each line of text
		while (fgets(line_of_text, LINE_BUFFER_SIZE, input_file) != NULL)
			printf(line_of_text);

		//close file
		fclose(input_file);
	}
}

//main entry point for the program
int main(int argc, char *argv[]) {
	
	//loops through all arguments for printing
	for (int index = 1; index < argc; index++)
		printFile(argv[index]);

	return 0;
}