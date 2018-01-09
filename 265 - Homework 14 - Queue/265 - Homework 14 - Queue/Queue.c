/*
Phillip Benoit
CIS 279
Fall 2017
*/

#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"

//number of elements in the list
static int LIST_COUNTER = 0;

//holds pointers to the first and last elelments in the list
static struct listElement *front = NULL, *back = NULL;

//adds a student to the list
void enqueue(int i) {

	//allocate memeory for the new link
	struct listElement *link = (struct listElement*)
		malloc(sizeof(struct listElement));

	//assign data for link
	link->value = i;

	//Initializes first and last if empty
	if (front == NULL) {
		front = link;
		link->previous = NULL;
	} else {
		//sets up link in the list
		back->next = link;
		link->previous = back;
	}

	//ajusts list to see link as the new back
	link->next = NULL;
	back = link;
	
	//step up counter
	LIST_COUNTER++;
}

//removes the item from the front of the queue and returns the value
int dequeue() {
	
	//get return value
	int return_value = front->value;

	//save new front location
	struct listElement *new_front = front->next;
	
	//remove link to previous element from the new front
	new_front->previous = NULL;
	
	//freee the memory used by the front element
	free(front);
	
	//assign new front
	front = new_front;
	
	//decrement the counter
	LIST_COUNTER--;
	
	//return the value from the removed item
	return return_value;
}

//returns value from front
int peekFront() {
	return front->value;
}

//returns value from the back
int peekBack() {
	return back->value;
}

//tests for an empty queue
bool isEmpty() {
	return (LIST_COUNTER == 0) ? true : false;
}

//returns the count of items in the queue
int getCount() {
	return LIST_COUNTER;
}

//displays the whole queue
void printList() {
	
	//cursor used to step through list
	struct listElement *output = front;

	//error message for empty list
	if (output == NULL) printf("The queue is empty.\n");

	//loops through list
	while (output != NULL) {

		//displays a single element
		printf("%d\n",output->value);

		//steps to next element
		output = output->next;
	}
}