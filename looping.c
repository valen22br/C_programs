/*
 ============================================================================
 Name        : looping.c
 Author      : Luis Gustavo Grubert Valensuela
 Version     :
 Class       : COP2220 T TR 02:00PM-03:30PM
 Professor   : Eduardo Fernandez
 Description : name in C, Ansi-style
 ============================================================================
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int userNumber;
	int count;
	printf("Please, enter a number from 1 to 9");
	scanf("%d", &userNumber);

	//Part 1
	count = userNumber;

	while (count != 0) {
		printf("FAU Owls - Hoot Hoot\n");
		count--;
	}

	for (count = userNumber; count != 0; count--) {
		printf("Programming is fun\n");
	}

	do {
		printf("Florida beaches are beautiful\n");
		userNumber--;
	} while (userNumber != 0);

	//Part 2
	double userNumber2;
	double sum = 0;
	count = 0;
	double avg;


	do {
		printf("\nPlease, enter a number. To exit enter -1 =>");
		scanf("%lf", &userNumber2);
		if(userNumber2 != -1){
			sum += userNumber2;
			count++;
		}

	} while (userNumber2 != -1);
	avg = sum/count;

	printf("\nYou entered %d total numbers. The sum of the numbers entered is %.2f, and the average is %.2f\n",count, sum,
			avg);
	printf("Have a Nice Day :)\n\n");

	return 0;
}
