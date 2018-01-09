/*
Phillip Benoit
CIS 279
Fall 2017
*/

#include <stdbool.h>

#ifndef QUEUE_H_
#define QUEUE_H_

struct listElement {
	int value;
	struct listElement *next, *previous;
};

static int LIST_COUNTER;

static struct listElement *front, *back;

void enqueue(int i);
int dequeue();
int peekFront();
int peekBack();
bool isEmpty();

int getCount();

void printList();

#endif
