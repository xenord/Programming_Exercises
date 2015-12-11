/*
 * main.c
 * es6
 *
 * Created by Francesco Benetello on 11/12/15.
 * Copyright (c) 2015 Francesco Benetello. All rights reserved.
 */

#include <stdio.h>


double calcAngularCoeff(double *x1, double *y1, double *x2, double *y2) {
	double m;
	m = ((*y2) - (*y1)) / ((*x2) - (*x1));
	return m;
}

double calcIntercetta (double *x1, double *y1, double *x2, double *y2) {
	double q;
	q = (((*x1) * (*y2)) - ((*x2) * (*y1))) / ((*x1) - (*x2));
	return q;
}

int main () {
	double x1, y1, x2, y2, m=0, q=0;
	printf("Enter the value of x1:\n");
	scanf("%lf", &x1);
	printf("Enter the value of y1:\n");
	scanf("%lf", &y1);
	printf("Enter the value of x2:\n");
	scanf("%lf", &x2);
	printf("Enter the value of y2:\n");
	scanf("%lf", &y2);
	m = calcAngularCoeff(&x1, &y1, &x2, &y2);
	q = calcIntercetta(&x1, &y1, &x2, &y2);
	if (x1 == x2 == y1 == y2) {
		printf("The given points are equals.\n");
		return 0;
	}
	else if ((x1 - x2) == 0){
		printf("The line is vertical.\n");
		return 0;
		}
		else if ((m == 1) && (q == 0)) {
				printf("The equation of the line goes through the origin: y = 1.000 * x\n");
				return 0;
			}
			else if ((m == 0) && (q == 1)) {
					printf("The equation of the line is constant: y = 1.000\n");
					return 0;
				}
				else {
					printf("y = %lf x + %lf\n",m, q);
					return 0;
				}
	return 0;
}
