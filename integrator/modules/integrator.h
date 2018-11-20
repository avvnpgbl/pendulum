#pragma once
double* model(double[]);
double* RK4(double*(*)(double[]), double[], double);