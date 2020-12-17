/* Andre Augusto Giannotti Scota (https://sites.google.com/view/a2gs/) */

/* From line 34 onwards comes from: */
/* File:     omp_hello.c
 *
 * Purpose:  A parallel hello, world program that uses OpenMP
 *
 * Compile:  gcc -g -Wall -fopenmp -o omp_hello omp_hello.c
 * Run:      ./omp_hello <number of threads>
 * 
 * Input:    none
 * Output:   A message from each thread
 *
 * IPP:      Section 5.1 (pp. 211 and ff.)
 */

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#include "openmp_util.h"

int main(int argc, char *argv[])
{
	int i = 0;
	int nthreads = 0, tid = 0;

	/* #pragma omp parallel num_threads(3) */
	/* omp_set_num_threads(2); */

	dumpEnviroment();

	#pragma omp parallel for
	for(i = 0; i < 4; ++i){
		printf("Hello World parallel for!\n");
	}

	/* Fork a team of threads giving them their own copies of variables */
	#pragma omp parallel private(nthreads, tid)
	{

		/* Obtain thread number */
		tid = omp_get_thread_num();
		printf("Hello World from thread = %d\n", tid);

		/* Only master thread does this */
		if (tid == 0){
			nthreads = omp_get_num_threads();
			printf("Number of threads = %d\n", nthreads);
		}

	}  /* All threads join master thread and disband */

	return(0);
}
