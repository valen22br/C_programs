/*
 ============================================================================
 Name        : function.c
 Author      : Luis Gustavo Grubert Valensuela
 Version     :
 Class       : COP2220 T TR 02:00PM-03:30PM
 Professor   : Eduardo Fernandez
 Description : name in C, Ansi-style
 ============================================================================
 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define PI 3.1415 /* Pi Constant */

/* Function prototype */
int GetInt(void);
int CalculateAreaRec(int length, int width);
double CalculateAreaCir(int radius);

int main(void) {

	int radius, /* radius of a circle */
	length, /* length of a square/rectangle */
	width, /* width of a square/rectangle */
	rectangleArea; /* area of the rectangle */

	double circleArea; /* area of the circle */

	printf("Please, enter the radius of the circle");
	radius = GetInt();
	circleArea = CalculateAreaCir(radius);
	printf("The area of the circle with %d radius is: %.3f\n", radius,
			circleArea);

	printf("Please, enter the length of a side of the rectangle");
	length = GetInt();

	printf("Please, enter the width of a side of the rectangle");
	width = GetInt();

	rectangleArea = CalculateAreaRec(length, width);
	printf("The area of the rectangle with length of %d and width of %d is: %d\n",
			length, width, rectangleArea);
	return 0;
}

/*
 * Get Integer values from the input
 * Pre: The input needs to be an integer value
 * */

int GetInt(void) {
	int intVariable;
	scanf("%d", &intVariable);
	return intVariable;
}

/*
 * Calculates the area of a rectangle
 * Pre: The inputs needs to be integers
 * */
int CalculateAreaRec(int length, int width) {
	return length * width;
}

/*
 * Calculates the area of a circle
 * Pre: The input needs to be integer
 * */
double CalculateAreaCir(int radius)
{
	return radius * radius * PI;
}
