/*
Phillip Benoit
CIS 279
Fall 2017
*/

//Max length of phone number is 14 characters (plus one to end the string properly)
#define MAX_PHONE_NUMBER_LENGTH 15

//input question
#define QUESTION "Please input a phone number that uses letters: (1-800-COLLECT)\n"

void ex4() {
	//allocate memory for phone number
	char *phone_number = malloc(MAX_PHONE_NUMBER_LENGTH * sizeof(char));
	
	//get input
	getString(QUESTION, phone_number, MAX_PHONE_NUMBER_LENGTH - 1);
	
	//counter to itterate through the string
	int index = 0;
	
	//loop through string until an end character is found
	while (phone_number[index] != '\0') {
		
		//replace character
		phone_number[index] = getNumber(phone_number[index]);
		
		//increase index to get next character
		index++;
	}

	//display output
	printf("The converted phone number is: %s\n\n", phone_number);
	
	//free memory for string
	free(phone_number);
}

//method with switch statement to convert characters
char getNumber(char digit) {
	switch (digit) {
	
	case 'A':
	case 'B':
	case 'C':
		return '2';

	case 'D':
	case 'E':
	case 'F':
		return '3';

	case 'G':
	case 'H':
	case 'I':
		return '4';

	case 'J':
	case 'K':
	case 'L':
		return '5';

	case 'M':
	case 'N':
	case 'O':
		return '6';

	case 'P':
	case 'Q':
	case 'R':
	case 'S':
		return '7';

	case 'T':
	case 'U':
	case 'V':
		return '8';

	case 'W':
	case 'X':
	case 'Y':
	case 'Z':
		return '9';

	//returns the same character by default
	default:
		return digit;
	}
}