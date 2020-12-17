/* Andre Augusto Giannotti Scota (https://sites.google.com/view/a2gs/) */

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#include "openmp_util.h"

int main(int argc, char *argv[])
{
	/* #pragma omp parallel num_threads(3) */
	/* omp_set_num_threads(2); */

	#pragma omp parallel
	{
		function_a(0);
		function_b(3);

		#pragma omp barrier

		#pragma omp master
		{
			printf("Join all threads.\n");
		}

	}

	function_c(1);
	function_d(0);

	return(0);
}
