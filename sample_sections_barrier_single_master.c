/* Andre Augusto Giannotti Scota (https://sites.google.com/view/a2gs/) */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <omp.h>

#include "openmp_util.h"

int main(int argc, char *argv[])
{
	/* #pragma omp parallel num_threads(3) */
	/* omp_set_num_threads(2); */

	dumpEnviroment();

	printf("Starting...\n\n");

	#pragma omp parallel
	{

		DEBUG(printf("Start section a\n");)
		function_a(0);
		DEBUG(printf("Start section a\n\n");)

		DEBUG(printf("Start section b (sleep)\n");)
		function_b(1);
		DEBUG(printf("End section b\n\n");)

		/* Explicit barrier */
		#pragma omp barrier

		/* Only one thread will run this */
		#pragma omp single
			printf("-----------------------------\n");

		DEBUG(printf("Start section c\n");)
		function_c(0);
		DEBUG(printf("End section c\n\n");)

		#pragma omp single
		{
			DEBUG(printf("Start section d\n");)
			function_d(0);
			DEBUG(printf("End section d\n\n");)
		}

		/* Only master (0) thread will run this */
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
