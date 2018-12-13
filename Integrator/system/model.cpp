#include "model.h"
#include <math.h>
//#define PI 3.14159265

const double g = 9.81;
const double L = 0.5;
static volatile double xbuf[n];

void model(volatile double* x)
{
	for (int i = 0; i < n; i++)
		xbuf[i] = x[i];

	x[0] = xbuf[1];
	x[1] = -(g / L)*sin(xbuf[0]);
}
