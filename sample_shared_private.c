/* Andre Augusto Giannotti Scota (https://sites.google.com/view/a2gs/) */

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#include "openmp_util.h"

int main(int argc, char *argv[])
{
	int factor, i, resultSum;
	long resultMul;

	factor = i = resultSum = 0;
	resultMul = 1;

	#pragma omp parallel shared(resultSum, resultMul) private(factor, i)
	{
		for(i = 1; i < 5; i++){
			factor = omp_get_thread_num() + i;

			#pragma omp critical
			{
				resultSum += factor;
				resultMul *= factor;
				printf("Thread Id: [%d] - Factor: [%d] - Sum: [%d] - Mult: [%ld]\n", omp_get_thread_num(), factor, resultSum, resultMul);
			}
		}
	}

	printf("\nThread Id: [%d] - Sum: [%d] - Mult: [%ld]\n", omp_get_thread_num(), resultSum, resultMul);

	return(0);
}
