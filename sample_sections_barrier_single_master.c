/* Andre Augusto Giannotti Scota (https://sites.google.com/view/a2gs/) */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <omp.h>

#include "openmp_util.h"

int main(int argc, char *argv[])
{

	dumpEnviroment();

	printf("Starting...\n\n");

	#pragma omp parallel
	{

		printf("Start section a\n");
		function_a();
		printf("Start section a\n\n");

		printf("Start section b (sleep)\n");
		function_b();
		sleep(1);
		printf("End section b\n\n");

		#pragma omp barrier /* Explicit barrier */

		#pragma omp single
			printf("-----------------------------\n");

		printf("Start section c\n");
		function_c();
		printf("End section c\n\n");

		#pragma omp single
		{
			printf("Start section d\n");
			function_d();
			printf("End section d\n\n");
		}

		#pragma omp master
		{
			printf("Only master thread print this. Thread Id: [%d]\n", omp_get_thread_num());
			sleep(1);
		}

	/* Implicit barrier here */
	}

	printf("End.\n");

	return(0);
}
