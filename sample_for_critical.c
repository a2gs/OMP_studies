/* Andre Augusto Giannotti Scota (https://sites.google.com/view/a2gs/) */

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#include "openmp_util.h"

int f(int a, int b, int c)
{
	return(a + b + c);
}

int main(int argc, char *argv[])
{
	int x[] = {1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 , 9 , 10};
	int y[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
	int z[] = {11, 22, 33, 44, 55, 66, 77, 88, 99, 111};
	int sum = 0;

	/* #pragma omp parallel num_threads(3) */
	/* omp_set_num_threads(2); */

	#pragma omp parallel for
	for(int i = 0; i < 10; ++i){

		int ctx = f(x[i], y[i], z[i]);

		/* Critical region. One thread per time */
		/* #pragma omp atomic */
		#pragma omp critical
		{
			printf("Thread Id:[%d] - i: [%d] - Ctx: [%d]\n", omp_get_thread_num(), i, ctx);
			sum += ctx;
		}
	}

	printf("Sum: [%d]\n", sum);

	return(0);
}
