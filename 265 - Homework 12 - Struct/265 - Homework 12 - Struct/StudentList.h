/*
Phillip Benoit
CIS 279
Fall 2017
*/

#include "Student.h"

#ifndef STUDENTLIST_H_
#define STUDENTLIST_H_

struct listElement {
	struct student student;
	struct listElement *next;
};

int LIST_COUNTER;

struct listElement *first, *last;

void addStudent(struct student s);
void printList();
struct student *findStudent(int id);
int * countCampuses();

#endif
