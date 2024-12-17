/*
--------------------------------------------------
 Project: a2q1
 File:    polynomial_ptest.c
 About:   public test driver
 Version: 2024-09-08
--------------------------------------------------
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "polynomial.h"

float p[] = {1, 2, 3, 4};
float x[] = {0, 1, 10};
float s[] = {-2, -1};

void display_polynomial(float p[], int n)
{
  for (int i = 0; i < n; i++)
  {
    if (i > 0 && p[i] > 0)
      printf("+");
    printf("%.2f", p[i]);
    if (i < n - 1)
      printf("*x^%d", n - i - 1);
  }
}

void test_horner()
{
	printf("------------------\n");
	printf("Test: horner\n\n");
	int n = sizeof(p) / sizeof(float);
	printf("p(x): ");
	display_polynomial(p, n);
	printf("\n");

	float x[] = {0, 1, 10};
	int count = sizeof(x) / sizeof(float);
	for (int i = 0; i < count; i++)
	{
		printf("horner(p %.2f): %.2f\n", x[i], horner(p, n, x[i]));
	}
	printf("\n");
}

void test_derivative()
{
	printf("------------------\n");
	printf("Test: derivative\n\n");
	int n = sizeof(p) / sizeof *p;
	float d[n - 1];
	derivative(p, d, n);
	printf("p'(x): ");
	display_polynomial(d, n - 1);
	printf("\n");
}

int main()
{
	test_horner();
	test_derivative();
	return 0;
}
