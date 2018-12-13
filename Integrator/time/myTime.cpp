#include "myTime.h"

#define _POSIX_C_SOURCE 200809L

#include <inttypes.h>
#include <time.h>

static int t0_flag=0;
static long double t0;

long double valid_time(void)
{
	struct timespec spec;
	//time_t sec;

    //sec = time (NULL);

	clock_gettime(CLOCK_REALTIME, &spec);
	return (long double)spec.tv_sec + (long double)spec.tv_nsec/1.0e9;
}

void set_init_time(void)
{
	t0_flag=1;
	t0=valid_time();
}

long double diff_time(void)
{
	if(!t0_flag)
		set_init_time();

	return (valid_time()-t0);
}
