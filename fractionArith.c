/*
 ============================================================================
 Name        : FractionArith.c
 Author      : Luis Gustavo Grubert Valensuela
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void scan_fraction(int *nump, int *denomp);
char get_operator(void);
void add_fractions(int n1, int d1, int n2, int d2, int *n_ansp, int *d_ansp);
void multiply_fractions(int n1, int d1, int n2, int d2, int *n_ansp,
		int *d_ansp);
int find_gcd(int n1, int n2);
void reduce_fraction(int *nump, int *denomp);
void print_fraction(int num, int denom);

int main(void) {

	int n1, d1;
	int n2, d2;
	char op;
	char again;
	int n_ans, d_ans; // numerator, denominator of answer
	// While the user wants to continue, gets and solves arithmetic
	// problems with common fractions
	do {
		// Gets a fraction problem
		scan_fraction(&n1, &d1);
		op = get_operator();
		scan_fraction(&n2, &d2);

		/* Computes the result */
		switch (op) {
		case '+':
			add_fractions(n1, d1, n2, d2, &n_ans, &d_ans);
			break;
		case '-':
			add_fractions(n1, d1, -n2, d2, &n_ans, &d_ans);
			break;
		case '*':
			multiply_fractions(n1, d1, n2, d2, &n_ans, &d_ans);
			break;
		case '/':
			multiply_fractions(n1, d1, d2, n2, &n_ans, &d_ans);
		}

		//		printf("1 fraction = %d/%d \n", n_ans, d_ans);
		reduce_fraction(&n_ans, &d_ans);

		//		printf("2 fraction = %d/%d \n", n_ans, d_ans);
		// Displays problem and result
		printf("\n");
		print_fraction(n1, d1);
		printf(" %c ", op);
		print_fraction(n2, d2);
		printf(" = ");
		print_fraction(n_ans, d_ans);

		// Asks user about doing another problem
		printf("\nDo another problem? (y/n)> ");
		scanf(" %c", &again);

	} while (again == 'y' || again == 'Y');

	return 0;
}

void scan_fraction(int *nump, int *denomp) {
	char slash; // Character between numerator and denominator
	int status; // status code returned by scanf indication
	// number of valid values obtained
	int error; //flag indicating presence of an error
	char discard; // unprocessed character from input line
	do {
		//No errors detected
		error = 0;
		//Get a fraction from the user
		printf("Enter a common fraction as two integers separated ");
		printf("by a slash> ");
		status = scanf("%d %c%d", nump, &slash, denomp);

		// Validate the fraction
		if (status < 3) {
			error = 1;
			printf("Invalid-please read directions carefully\n");
		} else if (slash != '/') {
			error = 1;
			printf("Invalid-separete numerator and denominator");
			printf(" by a slash (/)\n");
		} else if (*denomp <= 0) {
			error = 1;
			printf("Invalid-denominator must be positive\n");
		}

		// Discard extra input characters
		do {
			scanf("%c", &discard);
		} while (discard != '\n');

	} while (error);

}

char get_operator(void) {
	char op;
	printf("Enter an arithmetic operator (+,-,*, or /)\n> ");
	for (scanf("%c", &op); op != '+' && op != '-' && op != '*' && op != '/'; scanf(
			"%c", &op)) {
		if (op != '\n')
			printf("%c invalid, reenter operator (+,-, *,/)\n> ", op);
	}
	return (op);
}

void add_fractions(int n1, int d1, int n2, int d2, int *n_ansp, int *d_ansp) {

	//	printf("n1 = %d, d1 = %d, n2 = %d, d2 = %d \n", n1, d1, n2, d2);
	int denom; /* common denominator used for sum (may not be least)*/
	int numer; // numerator of sum
	int sign_factor; // -1 for a negative, 1 otherwise
	// Finds a common denominator
	denom = d1 * d2;
	// Computes numerator
	numer = n1 * d2 + n2 * d1;
	// Adjusts sign (at most, numerator should be negative)

	if (numer * denom >= 0)
		sign_factor = 1;
	else
		sign_factor = -1;
	numer = sign_factor * abs(numer);
	denom = abs(denom);
	// Returns result
	//	printf("numer = %d \n", numer);
	*n_ansp = numer;
	*d_ansp = denom;
}
//stub
void multiply_fractions(int n1, int d1, int n2, int d2, int *n_ansp,
		int *d_ansp) {
	// Displays trace message
	//	printf("\nEntering multiply_fractions with\n");
	//	printf("n1 = %d, d1 = %d, n2 = %d, d2 = %d\n", n1, d1, n2, d2); // Defines output arguments
	*n_ansp = n1 * n2;
	if (d1 * d2 == 0) {
		printf("Denominator can not be zero");
		*d_ansp = 1;
	} else {
		*d_ansp = d1 * d2;
	}

}
//stub
int find_gcd(int n1, int n2) {

	//		printf("n1 = %d, n2 = %d \n", n1, n2);
	//	int gcd;
	int q;
	int p;
	int r;

	q = abs(n1);
	p = abs(n2);
	//		printf("1- The gcd is %d \n",p);
	r = q % p;
	//		printf("2- The gcd is %d \n",p);
	//		printf("r= %d \n",r);
	while (r != 0) {
		q = p;
		p = r;
		r = q % p;
	}

	//	/* Displays trace message */
	//	printf("\nEntering find_gcd with n1 = %d, n2 = %d\n", n1, n2);
	//	/* Asks user for gcd */
	//	printf("gcd of %d and %d?> ", n1, n2);
	//	scanf("%d", &gcd);
	//	/* Displays exit trace message */
	//	printf("find_gcd returning %d\n", gcd);
	//	printf("The gcd is %d \n", p);
	return (p);
}

void reduce_fraction(int *nump, int *denomp) {
	int gcd; /* greatest common divisor of numerator & denominator */
	gcd = find_gcd(*nump, *denomp);
	//	printf("gcd = %d \n", gcd);

	*nump = *nump / gcd;
	*denomp = *denomp / gcd;
}

void print_fraction(int num, int denom) {
	printf("%d/%d", num, denom);
}

