#include "model.h"
#include "RK4.h"

static const double a[n_method][n_method]={
										{0.0,	0.0,	0.0,	0.0},
										{0.5,	0.0,	0.0,	0.0},
										{0.0,	0.5,	0.0,	0.0},
										{0.0,	0.0,	1.0,	0.0}
									};

static const double c[n_method] = { 0.0,	0.5,	0.5,	1.0 };
static const double b[n_method] = { 0.166666667,	1.0/3.0,	1.0/3.0,	0.166666667 };

static double k[n][n_method];
static volatile double xbuf[n];


void RK4(volatile double* x0, double h)
{


	for (int i = 0; i < n; i++)
		xbuf[i] = x0[i];

	for (int i = 0; i < n_method; i++)
	{
			for (int j = 0; j < n; j++)
				xbuf[j] = x0[j] + h * k[j][i - 1] * a[i][i - 1];

		model(xbuf);

		for (int j = 0; j < n; j++)
			k[j][i] = xbuf[j];
	}

	for (int i = 0; i < n_method; i++)
		for (int j = 0; j < n; j++)
			x0[j] = x0[j] + h * k[j][i] * b[i];
}
