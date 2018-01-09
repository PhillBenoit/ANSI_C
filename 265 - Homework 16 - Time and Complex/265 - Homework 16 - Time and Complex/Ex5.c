/*
Phillip Benoit
CIS 279
Fall 2017
*/

#include <stdio.h>
#include <time.h>
#include <string.h>
#include <math.h>
#include "Ex5.h"
#include "Input.h"

#define TIME_INPUT_1 "Please input the firts date (MM/DD/YYYY)"
#define TIME_INPUT_2 "Please input the second date (MM/DD/YYYY)"
#define DATE_ERROR "Date not recognized.  Please try again"

//gets a time value from user input
time_t getTime(char *question) {
	
	//holds strings
	char month[3], day[3], year[5], user_input[11];
	
	//struct to feed to mktime
	struct tm time_structure;
	
	//result of mktime
	time_t return_time;

	do {

		do {
			//get user input
			getString(question, user_input, 10);
			
			//display error if user input isn't long enough
			if (strlen(user_input) < 10) printf("%s\n", DATE_ERROR);
		
		//loop until user input is the correct length
		} while (strlen(user_input) < 10);
		
		//parse user inout
		month[0] = user_input[0];
		month[1] = user_input[1];
		day[0] = user_input[3];
		day[1] = user_input[4];
		year[0] = user_input[6];
		year[1] = user_input[7];
		year[2] = user_input[8];
		year[3] = user_input[9];
		
		//assign user inout to the time structure
		time_structure.tm_mon = atoi(month) - 1;
		time_structure.tm_mday = atoi(day);
		time_structure.tm_year = atoi(year) - 1900;
		
		//assign necessary value to complete mktime
		time_structure.tm_hour = 0;
		time_structure.tm_min = 0;
		time_structure.tm_sec = 0;
		
		//get time from structure
		return_time = mktime(&time_structure);
		
		//if mktime was not successful, print an error message
		if (return_time == -1) printf("%s\n", DATE_ERROR);
	
	//loop untime mktime is successful
	} while (return_time == -1);

	//retuen time value
	return return_time;
}

void ex5() {
	
	//varuables to hold the day values
	time_t day1, day2;

	//get user input
	day1 = getTime(TIME_INPUT_1);
	day2 = getTime(TIME_INPUT_2);

	//calulte difference
	int result = abs((int)(difftime(day1, day2) / 86400));

	//print results
	printf("There are %d days between the two dates.\n", result);

	pause();
}
