#include "pch.h"
#include "math.h"
#define n 2

double* model(double x0[n])
{
	const double g = 9.81;
	const double L = 0.5;
	double x[n];

	x[0] = x0[1];
	x[1] = -(g / L)*sin(x0[0]);
	return x;
}