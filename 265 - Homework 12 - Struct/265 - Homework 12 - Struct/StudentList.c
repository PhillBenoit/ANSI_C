/*
Phillip Benoit
CIS 279
Fall 2017
*/

#include <stdio.h>
#include <stdlib.h>
#include "Student.h"
#include "StudentList.h"

//number of elements in the list
int LIST_COUNTER = 0;

//holds pointers to the first and last elelments in the list
struct listElement *first = NULL, *last = NULL;

//adds a student to the list
void addStudent(struct student s) {

	//allocate memeory for the new link
	struct listElement *link = (struct listElement*)
		malloc(sizeof(struct listElement));

	//assign data for link
	link->student = s;

	//Initializes first and last if empty
	if (first == NULL) {
		first = link;
		last = link;
	}

	//sets up the link in the list
	last->next = link;
	link->next = NULL;
	last = link;

	//step up counter
	LIST_COUNTER++;
}

//displays all students in the list
void printList() {
	
	//cursor used to step through list
	struct listElement *output = first;

	//error message for empty list
	if (output == NULL) printf("No students to display.\n");

	//loops through list
	while (output != NULL) {

		//displays a single element
		printStudent(output->student);

		//steps to next element
		output = output->next;
	}
}

//find student by ID, returns found student or null for no match
struct student * findStudent(int id) {

	//pointer used to return
	struct student *return_student = NULL;
	
	//cursor used to step through the list
	struct listElement *cursor = first;

	//steps through the list until the end or a match is found
	while (cursor != NULL && cursor->student.id != id) cursor = cursor->next;

	//if a match is found, it's address is given for return
	if (cursor != NULL) return_student = &cursor->student;

	//return the address of the found student
	return return_student;
}

//counts the number of students assigned to each campus
int * countCampuses() {

	//return variable that holds the count for each capus
	//each campus has an enumerated index in the array
	static int count[NUMBER_OF_CAMPUSES];

	//cursor for stepping through the list
	struct listElement *cursor = first;

	//loops tyhrough the whole list
	while (cursor != NULL) {

		//increases the count at the index of the enumerated capus
		count[cursor->student.campus]++;
		
		//steps to next element in the list
		cursor = cursor->next;
	}

	//returns the array with the count for each campus
	return count;
}