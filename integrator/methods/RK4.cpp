#include "pch.h"
#include "model.h"
#include "dimensions.h"

extern const int n_method;
extern const int n;

void RK4(double* x0, double h)
{
	const double a[n_method][n_method] = { {0,0,0,0},
										 {0.5,0,0,0},
										 {0,0.5,0,0},
										 {0,0,1,0 } };
	const double c[n_method] = { 0,0.5,0.5,1 };
	const double b[n_method] = { 0.166666666,0.333333333,0.333333333,0.166666666 };

	double k[n][n_method];
	double xbuf[n];

	for (int i = 0; i < n; i++)
	{
		xbuf[i] = x0[i];
	}

	for (int i = 0; i < n_method; i++)
	{
		if (i > 0)
		{
			for (int j = 0; j < n; j++)
			{
				xbuf[j] = x0[j] + h * k[j][i - 1] * a[i][i - 1];
			}
		}

		model(xbuf);

		for (int j = 0; j < n; j++)
		{
			k[j][i] = xbuf[j];
		}
	}

	for (int i = 0; i < n_method; i++)
	{
		for (int j = 0; j < n; j++)
		{
			x0[j] = x0[j] + h * k[j][i] * b[i];
		}
	}
}