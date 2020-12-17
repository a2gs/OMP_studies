#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <omp.h>

int function_a(int x)
{
	printf("A: Inside function A (sleep: [%d]). Thread Id: [%d]\n", x, omp_get_thread_num());

	if(x != 0)
		sleep(x);

	return(0);
}

int function_b(int x)
{
	printf("B: Inside function B (sleep: [%d]). Thread Id: [%d]\n", x, omp_get_thread_num());

	if(x != 0)
		sleep(x);

	return(0);
}

int function_c(int x)
{
	printf("C: Inside function C (sleep: [%d]). Thread Id: [%d]\n", x, omp_get_thread_num());

	if(x != 0)
		sleep(x);

	return(0);
}

int function_d(int x)
{
	printf("D: Inside function D (sleep: [%d]). Thread Id: [%d]\n", x, omp_get_thread_num());

	if(x != 0)
		sleep(x);

	return(0);
}

int dumpEnviroment(void)
{
	printf("OMP_SCHEDULE...: [%s]\n", getenv("OMP_SCHEDULE"));
	printf("OMP_NUM_THREADS: [%s]\n", getenv("OMP_NUM_THREADS"));
	printf("OMP_DYNAMIC....: [%s]\n", getenv("OMP_DYNAMIC"));
	printf("OMP_NESTED.....: [%s]\n", getenv("OMP_NESTED"));

	return(0);
}
