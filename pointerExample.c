/*
 ============================================================================
 Name        : pointers.c
 Author      : Luis Gustavo Grubert Valensuela
 Version     :
 Class       : COP2220 T TR 02:00PM-03:30PM
 Professor   : Eduardo Fernandez
 Description : Program to calculate the sum and product by 3 different
 	 	 	   	   functions:
               function int CalculateProd (int num1, int num2)
               	   calculates and returns the sum;
               function int CalculateSum(int num1, int num2)
               	   calculates and returns the product;
               function void CalculateBoth(int num1, int num2, int*prodPtr, int *sumPtr);
               	   calculates both the sum and product modifying pointers.
 ============================================================================
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

/* functions prototypes */
int CalculateProd (int num1, int num2);
int CalculateSum(int num1, int num2);
void CalculateBoth(int num1, int num2, int *prodPtr, int *sumPtr);

int main(void) {


	int num1,
		num2,
		status,
		prodPtr = 0,
		sumPtr = 0;


	printf("Please enter two integer numbers separeted by a space: ");
	status = scanf("%d %d", &num1, &num2);
	if (status == 2){

	printf("Return value of function CalculateProd => %d\n\n", CalculateProd(num1, num2));
	printf("Return value of function CalculateSum => %d\n\n", CalculateSum(num1, num2));

	CalculateBoth(num1, num2, &prodPtr, &sumPtr);

	printf("Modified pointer by function CalculateBoth => product value: %d\n", prodPtr);
	printf("Modified pointer by function CalculateBoth => sum value:  %d\n", sumPtr);




	}
	else{
		printf("The values entered are invalid. Please execute the program again.:\n");
	}


	return 0;
}

int CalculateProd(int num1, int num2){
	int product;
	product = num1 * num2;
	printf("Inside function definition CalculateProd => product value: %d\n", product);
	return product;
}

int CalculateSum(int num1, int num2){
	int sum;
	sum = num1 + num2;
	printf("Inside function definition CalculateSum => sum value: %d\n", sum);
	return sum;
}

void CalculateBoth(int num1, int num2, int *prodPtr, int *sumPtr){
	*prodPtr = num1 * num2;
	*sumPtr = num1 + num2;
	printf("Inside function definition CalculateBoth => product value: %d\n", *prodPtr);
	printf("Inside function definition CalculateBoth => sum value: %d\n", *sumPtr);
}
