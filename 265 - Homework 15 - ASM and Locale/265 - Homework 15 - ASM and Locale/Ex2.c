/*
Phillip Benoit
CIS 279
Fall 2017
*/

#include <stdio.h>
#include <locale.h>
#include "Ex2.h"
#include "Input.h"

#define INPUT_QUESTION "Please input a locale"

void ex2() {
	
	//varible to hold input
	char user_input[6];
	
	//holds results of setlocale for testing
	char *valid = NULL;
	
	do {
		//get user input
		getString(INPUT_QUESTION, user_input, 5);
		
		//set locale
		valid = setlocale(LC_ALL, user_input);
		
		//display error if necessary
		if (valid == NULL) printf("Locale not recognized.  Please try again.\n");
	
	//run loop until a valid entry is found
	} while (valid == NULL);

	//pointer to new locale info
	struct lconv * lc = NULL;
	lc = localeconv();

	//output of struct members
	printf("Locale name: %s\n\n", valid);
	printf("dec_point = \"%s\"\n", lc->decimal_point);
	printf("thousands_sep = \"%s\"\n", lc->thousands_sep);
	printf("grouping = %d\n", *lc->grouping);
	printf("mon_decimal_point = \"%s\"\n", lc->mon_decimal_point);
	printf("mon_thousands_sep = \"%s\"\n", lc->mon_thousands_sep);
	printf("mon_grouping = %d\n", *lc->mon_grouping);
	printf("positive_sign = \"%s\"\n", lc->positive_sign);
	printf("negative_sign = \"%s\"\n", lc->negative_sign);
	printf("currency_symbol = \"%s\"\n", lc->currency_symbol);
	printf("frac_digits = %d\n", lc->frac_digits);
	printf("p_cs_precedes = %d\n", lc->p_cs_precedes);
	printf("n_cs_precedes = %d\n", lc->n_cs_precedes);
	printf("p_sep_by_space = %d\n", lc->p_sep_by_space);
	printf("n_sep_by_space = %d\n", lc->n_sep_by_space);
	printf("p_sign_posn = %d\n", lc->p_sign_posn);
	printf("n_sign_posn = %d\n", lc->n_sign_posn);
	printf("int_curr_symbol = \"%s\"\n", lc->int_curr_symbol);
	printf("int_frac_digits = %d\n\n", lc->int_frac_digits);

	pause();
}
