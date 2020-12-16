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
		#pragma omp sections nowait
		{

			#pragma omp section
			{
				printf("Start section a (sleep)\n");
				function_a();
				sleep(1);
				printf("Start section a\n\n");
			}

			#pragma omp section
			{
				printf("Start section b\n");
				function_b();
				printf("End section b\n\n");
			}

			#pragma omp section
			{
				printf("Start section c\n");
				function_c();
				printf("End section c\n\n");
			}

		/* NO implicit barrier here */
		}

		printf("End 1.\n");

	/* Implicit barrier here */
	}

	printf("End 2.\n");

	return(0);
}
