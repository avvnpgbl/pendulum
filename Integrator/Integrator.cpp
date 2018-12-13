#include "Integrator.h"
#include "myTime.h"
#include "RK4.h"

#include <iostream>
#include <fstream>
using namespace std;

long double t1=0.0;
long double t=0.0;
long double T=10.0;
double x0[n] = { 0.7,0.0 };
volatile double x[n];

int IntegratorThread(bool *exit_flag, bool *start_flag,bool *stop_flag)
{
	while(!(*exit_flag))
	{
		if((*start_flag))
		{
			ofstream out_x1;
			out_x1.open("./x1.txt");
			ofstream out_x2;
			out_x2.open("./x2.txt");
			ofstream out_t;
			out_t.open("./t.txt");

			for (int i = 0; i < n; i++)
				x[i] = x0[i];

			set_init_time();
			t=diff_time();

			while(!(*stop_flag))
			{
				t=diff_time();
				RK4(x, t-t1);
				out_x1<<x[0]<<"\n";
				out_x2<<x[1]<<"\n";
				out_t<<t<<"\n";

				cout<<t<<"\n";

				t1=t;
			}

			out_x1.close();
			out_x2.close();
			out_t.close();

			*stop_flag=false;
			*start_flag=false;
		}
	}

	*exit_flag=false;

	return 0;
}

