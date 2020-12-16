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

	#pragma omp parallel sections
	{

		#pragma omp section
		{
			printf("Start section a\n");
			function_a();
			printf("Start section a\n\n");
		}

		#pragma omp section
		{
			printf("Start section b (sleep)\n");
			function_b();
			sleep(1);
			printf("End section b\n\n");
		}

		#pragma omp section
		{
			printf("Start section c\n");
			function_c();
			printf("End section c\n\n");
		}

	/* Implicit barrier here */
	}

	printf("End.\n");

	return(0);
}
