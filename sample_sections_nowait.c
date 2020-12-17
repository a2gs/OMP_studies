/* Andre Augusto Giannotti Scota (https://sites.google.com/view/a2gs/) */

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#include "openmp_util.h"

int main(int argc, char *argv[])
{
	/* #pragma omp parallel num_threads(3) */
	omp_set_num_threads(2);

	dumpEnviroment();

	printf("Starting...\n\n");

	#pragma omp parallel
	{
		#pragma omp sections nowait
		{

			#pragma omp section
			{
				DEBUG(printf("Start section a (sleep)\n");)
				function_a(1);
				DEBUG(printf("Start section a\n\n");)
			}

			#pragma omp section
			{
				DEBUG(printf("Start section b\n");)
				function_b(0);
				DEBUG(printf("End section b\n\n");)
			}

			#pragma omp section
			{
				DEBUG(printf("Start section c\n");)
				function_c(3);
				DEBUG(printf("End section c\n\n");)
			}

		/* NO implicit barrier here */
		}

		printf("End 1.\n");

	/* Implicit barrier here */
	}

	function_d(4);

	printf("End 2.\n");

	return(0);
}
