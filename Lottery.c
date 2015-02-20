/*
 * Lottery.c
 *
 *  Created on: Oct 2, 2014
 *      Author: Halil Yavuz Çevik
 */


/* Aim : 1-) Draw 1000 Times
 *
 *       2-) Numbers must be between 1,49 ( including 1 and 49 )
 *
 *       3-) In each draw, we only draw a number one time
 *
 *       4-) Searching for how many times each number was in the winning numbers
 */



#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

	int arraycount[49] = { };
	//for registering the quantity of numbers that machine will chose
	int arraycontrol[49] = { };
	//for controlling numbers if they have chosen or not
	int num, counter1, counter2, counter3, counter4;

	srand(time(NULL));

	for (counter1 = 0; counter1 < 1000; counter1++) {
		for (counter2 = 0; counter2 < 6; counter2++) {

			num = rand() % 49 + 1;

			while (arraycontrol[num - 1] != 0)
				num = rand() % 49 + 1;

			arraycontrol[num - 1] = 1;
			arraycount[num - 1] += 1;
		}
		for (counter3 = 0; counter3 < 49; counter3++)
			arraycontrol[counter3] = 0;
	}
	for (counter4 = 0; counter4 < 49; counter4++)
		printf("%d\t%d\n", counter4 + 1, arraycount[counter4]);

	return 0;
}

