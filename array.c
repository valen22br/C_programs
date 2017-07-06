/*
 ============================================================================
 Name        : arrays.c
 Author      : Luis Gustavo Grubert Valensuela
 Version     :
 Class       : COP2220 T TR 02:00PM-03:30PM
 Professor   : Eduardo Fernandez
 Description : that fills an array of doubles with user input, prints the
 	 	 	   doubles on the screen in a column, and adds up all the doubles
 	 	 	   in the array and prints the sum onto the screen.
Functions    :
				int get_int(int n_min, int n_max);
				double get_double(int n_min, int n_max);
				void fillArray(double arrayValues[],int size);
				void printArray(double arrayValues[], int arraySize);
				void sumArray(double arrayValues[], int arraySize, double *sum);
 ============================================================================
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// Functions Prototypes
int get_int(int n_min, int n_max);
double get_double(int n_min, int n_max);
void fillArray(double arrayValues[],int size);
void printArray(double arrayValues[], int arraySize);
void sumArray(double arrayValues[], int arraySize, double *sum);

int main(void) {
	double arrayValues[20];
	int arraySize;
	double sum=0;

	arraySize = get_int(0, 20);
	fillArray(arrayValues, arraySize);
	printArray(arrayValues, arraySize);
	sumArray(arrayValues, arraySize, &sum);
	printf("The sum of the array is: %0.2f\n", sum);



	return 0;
}

/*
* Prompt the user to enter integer values in the inteval specified
* Pre: n_min and n_max are defined
* Post: Return the integer value.
*/
int get_int(int n_min, int n_max) {
	int in_val, status;
	/* input - number entered by user *//* status value returned by scanf *//* character to skip *//* error flag for bad input */
	char skip_ch;
	int error;
	/* Get data from user until in_val is in the range. */
	do {
		/* No errors detected yet. */
		error = 0;
		/* Get a number from the user. */
		printf("Enter an integer in the range from %d ", n_min);
		printf("to %d inclusive> ", n_max);
		status = scanf("%d", &in_val);
		/* Validate the number. */
		if (status != 1) { /* in_val didn't get a number */
			error = 1;
			scanf("%c", &skip_ch);
			printf("Invalid character >>%c>>. ", skip_ch);
			printf("Skipping rest of line.\n");
		} else if (in_val < n_min || in_val > n_max) {
			error = 1;
			printf("Number %d is not in range.\n", in_val);
		}
		/* Skip rest of data line. */
	} while (error);
	return (in_val);
}

/*
* Prompt the user to enter double values in the inteval specified
* Pre: n_min and n_max are defined
* Post: Return the double value.
*/
double get_double(int n_min, int n_max) {
	int status;
	double in_val;
	/* input - number entered by user *//* status value returned by scanf *//* character to skip *//* error flag for bad input */
	char skip_ch;
	int error;
	/* Get data from user until in_val is in the range. */
	do {
		/* No errors detected yet. */
		error = 0;
		/* Get a number from the user. */
		printf("Enter an double number: ");
		status = scanf("%lf", &in_val);
		/* Validate the number. */
		if (status != 1) { /* in_val didn't get a number */
			error = 1;
			scanf("%c", &skip_ch);
			printf("Invalid character >>%c>>. ", skip_ch);
			printf("Skipping rest of line.\n");
		} else if (in_val < n_min || in_val > n_max) {
			error = 1;
			printf("Number %f is not in range.\n", in_val);
		}
		/* Skip rest of data line. */
	} while (error);
	return (in_val);
}

/*
* Fill an double array with user's input
* Pre: arrayValues[] and Size are defined.
* Post: Array filled with input doubles values.
*
*
*
*
*/
void fillArray(double arrayValues[], int size)
{
	int count;
	for(count = 0; count < size; count++)
	{
//		printf("Enter the number in position %d of a total of %d positions\n", count+1, size );
		arrayValues[count] = get_double(-2147483648, 2147483647);
	}
}

/*
* Prints the content of an array in columns
* Pre: arrayValues[] and arraySize are defined.
* Post: printf output of array values arranged in columns
*/
void printArray(double arrayValues[], int arraySize)
{
	int count;
	printf("\nValues inside the array: \n");
	for(count = 0; count < arraySize; count++)
	{
		printf(" %.2f\n", arrayValues[count]);
	}
	printf("\n");
}

/*
* Sum the content of a dobule array
* Pre: arrayValues[] and arraySize, and sum are defined.
* Post: atribute the sum of the array items into pointer *sum
*/
void sumArray(double arrayValues[], int arraySize, double *sum)
{
	int count;
	for(count = 0; count < arraySize; count++)
	{
		*sum += arrayValues[count];
	}
}



