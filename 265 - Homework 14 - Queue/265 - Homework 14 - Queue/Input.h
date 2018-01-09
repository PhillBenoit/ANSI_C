/*
Phillip Benoit
CIS 279
Fall 2017
*/

#ifndef INPUT_H_
#define INPUT_H_

#include <stdbool.h>

void getWord(char *question, char *return_string, unsigned max);
void getString(char *question, char *return_string, unsigned max);
int intLoop(char *question);
int getInt(char *question, int min, int max);
int doubleLoop(char *question);
void getDouble(char *question, double min, double max, double *value);
bool getYN(char *question);

#endif
