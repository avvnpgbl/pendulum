#include "pch.h"
#define n_method 4
#define n 2

double* RK4(double*(*model)(double[]), double x0[], double h)
{
	const double a[n_method][n_method] = { {0,0,0,0},
						{0.5,0,0,0},
						{0,0.5,0,0},
						{0,0,1,0 } };
	const double c[n_method] = { 0,0.5,0.5,1 };
	const double b[n_method] = { 0.166666666,0.333333333,0.333333333,0.166666666 };

	double k[n][4];
	double* xbuf;
	double x[n];

	for (int i = 0; i < n_method; i++)
	{
		if (i > 0)
		{
			for (int j = 0; j < n; j++)
			{
				x0[j] = x0[j] + h * k[j][i - 1] * a[i][i - 1];
			}
		}

		xbuf = model(x0);
		for (int j = 0; j < n; j++)
		{
			k[j][i] = *(xbuf + j);
		}
	}

	for (int i = 0; i < n_method; i++)
	{
		for (int j = 0; j < n; j++)
		{
			x[j] = x0[j] + h * k[j][i] * b[i];
		}
	}

	return x;

}