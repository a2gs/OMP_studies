#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int function_a(void)
{
	printf("Inside function a. Thread Id: [%d]\n", omp_get_thread_num());
	return(0);
}

int function_b(void)
{
	printf("Inside function b. Thread Id: [%d]\n", omp_get_thread_num());
	return(0);
}

int function_c(void)
{
	printf("Inside function c. Thread Id: [%d]\n", omp_get_thread_num());
	return(0);
}

int function_d(void)
{
	printf("Inside function d. Thread Id: [%d]\n", omp_get_thread_num());
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
