/*
 ============================================================================
 Name        : area.c
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

int main(void) {

	int radius, /* radius of a circle */
		length, /* length of a square/rectangle */
		width,  /* width of a square/rectangle */
		rectangleArea; /* area of the rectangle */

	double circleArea; /* area of the circle */

	printf("Please, enter the radius of the circle");
	scanf("%d", &radius);
	circleArea = PI * radius * radius;
	printf("The area of the circle with %d radius is: %.3f\n", radius, circleArea);

	printf("Please, enter the length of a side of the rectangle");
	scanf("%d", &length);
	printf("Please, enter the width of a side of the rectangle");
	scanf("%d", &width);
	rectangleArea = width * length;

	printf("The area of the rectangle with length of %d and width of %d is: %d", length, width, rectangleArea);

	return 0;
}
