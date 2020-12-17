/* Andre Augusto Giannotti Scota (https://sites.google.com/view/a2gs/) */

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#include "openmp_util.h"

int main(int argc, char *argv[])
{
	/* #pragma omp parallel num_threads(3) */
	/* omp_set_num_threads(2); */

	dumpEnviroment();

	printf("Starting...\n\n");

	#pragma omp parallel sections
	{

		#pragma omp section
		{
			DEBUG(printf("Start section a\n");)
			function_a(0);
			DEBUG(printf("Start section a\n\n");)
		}

		#pragma omp section
		{
			DEBUG(printf("Start section b (sleep)\n");)
			function_b(1);
			DEBUG(printf("End section b\n\n");)
		}

		#pragma omp section
		{
			DEBUG(printf("Start section c\n");)
			function_c(0);
			DEBUG(printf("End section c\n\n");)
		}

	/* Implicit barrier here */
	}

	printf("End.\n");

	return(0);
}
