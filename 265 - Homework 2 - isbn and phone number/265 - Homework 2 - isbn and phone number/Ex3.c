/*
Phillip Benoit
CIS 279
Fall 2017
*/

void ex3() {
	//declare integers to hold values
	int gs1 = 0, group = 0, publisher = 0, item = 0, check = 0;
	
	//input question
	printf("Please input an ISBN: (xx-xx-xx-xx-xx)\n");
	
	//get input
	scanf("%d-%d-%d-%d-%d", &gs1, &group, &publisher, &item, &check);
	
	//print parsed output
	printf("GS1 prefix: %d\n"
		"Group identifier: %d\n"
		"Publisher code: %d\n"
		"Item number: %d\n"
		"Check digit: %d\n", gs1, group, publisher, item, check);
}