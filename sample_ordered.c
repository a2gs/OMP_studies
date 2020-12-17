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

	#pragma omp parallel for ordered
	for(int i = 0; i < 20; ++i){

		#pragma omp ordered
		{
			if(i % 2 == 0)
				sleep(2);

			printf("Thread Id: [%d] - i: [%d]\n",omp_get_thread_num(), i);
		}
	}

	return(0);
}
