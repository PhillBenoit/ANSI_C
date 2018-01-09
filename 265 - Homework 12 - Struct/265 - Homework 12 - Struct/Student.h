/*
Phillip Benoit
CIS 279
Fall 2017
*/

#ifndef STUDENT_H_
#define STUDENT_H_

#define MAX_NAME_LENGTH 31

#define NUMBER_OF_MAJORS 4
#define NUMBER_OF_CAMPUSES 3

enum MAJOR {
	Computer_Science, Interior_Design, Civil_Engineering,
	Accounting, Major_Not_Found = -1
};

char *MAJOR_STRING[NUMBER_OF_MAJORS];

enum CAMPUS {
	East, West, Downtown, Campus_Not_Found = -1
};

char *CAMPUS_STRING[NUMBER_OF_CAMPUSES];

struct student {
	int id, major, campus;
	char name[MAX_NAME_LENGTH + 1];
};

void printStudent(struct student s);

int enumerateMajor(char *string);

int enumerateCampus(char *string);

#endif
