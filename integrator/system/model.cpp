#include "pch.h"
#include "math.h"
#include "dimensions.h"

extern const int n;

void model(double* x)
{
	const double g = 9.81;
	const double L = 0.5;
	double xbuf[n];

	for (int i = 0; i < n; i++)
	{
		xbuf[i] = x[i];
	}

	x[0] = xbuf[1];
	x[1] = -(g / L)*sin(xbuf[0]);
}