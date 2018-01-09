/*
Phillip Benoit
CIS 279
Fall 2017
*/

#include <stdio.h>
#include <string.h>
#include "Student.h"

//string value of enumerated majors
char *MAJOR_STRING[NUMBER_OF_MAJORS] = {
	"Computer Science",
	"Interior Design",
	"Civil Engineering",
	"Accounting"
};

//string value of enumerated campuses
char *CAMPUS_STRING[NUMBER_OF_CAMPUSES] = {
	"East Campus",
	"West Campus",
	"Downtown Campus"
};

//displays passed student
void printStudent(struct student s) {
	printf("%-6d %-31s %-17s %-15s\n",
		s.id,
		s.name,
		MAJOR_STRING[s.major],
		CAMPUS_STRING[s.campus]
	);
}

//steps through String values of majors looking for a match
//if string matches an enumerated index, it returns that index value
//returns -1 if no match is found
int enumerateMajor(char * string) {
	int return_value = Major_Not_Found;
	for (int index = Computer_Science;
		index < NUMBER_OF_MAJORS && return_value == Major_Not_Found;
		index++)
		if (strcmp(string, MAJOR_STRING[index]) == 0) return_value = index;
	return return_value;
}

//steps through String values of campuses looking for a match
//if string matches an enumerated index, it returns that index value
//returns -1 if no match is found
int enumerateCampus(char * string) {
	int return_value = Campus_Not_Found;
	for (int index = East;
		index < NUMBER_OF_CAMPUSES && return_value == Campus_Not_Found;
		index++)
		if (strcmp(string, CAMPUS_STRING[index]) == 0) return_value = index;
	return return_value;
}
