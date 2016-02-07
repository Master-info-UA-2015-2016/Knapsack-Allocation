#include <stdio.h>
#include <stdlib.h>
#include <sys/timeb.h>

#include "file.h"
#include "knapsack.h"

int main(int argc, char **argv) {

    struct timeb t0, t1;    /* Timers */
    double cpu_time;        /* Time */
    
    ftime(&t0);
    
	int * sol;
	int i;
	
	tab_knapsack tab_k;
	int ** z;
	int ** x;

	if (argc != 2) {
		fprintf(stderr, "\nPlease, call the program with only one argument, that is the items file name.\n");
		exit(EXIT_FAILURE);
	}
	else {
		loadInstance(argv[1], &(tab_k.nb_items), &(tab_k.capacity), &(tab_k.items));
		
		// Creation of arrays Z and X
		allocate_tab(&z, tab_k.capacity, tab_k.nb_items);
		allocate_tab(&x, tab_k.capacity, tab_k.nb_items);
		sol = (int *)malloc((tab_k.nb_items)*sizeof(int));

		// Search of maximum profit by number f crate by location, stored into Z and X
		dynamic_optimal(&tab_k, &z, &x);
		optimal_solution(&tab_k, &x, &sol, tab_k.capacity, tab_k.nb_items-1);
		printf("\nItem in the knapsack : \n");
		for (i = 0; i < tab_k.nb_items; ++i) {
			if (sol[i] == 1) printf("%d ", i+1);
		}	
		printf("\nOptimal profit is %d \n", z[tab_k.capacity][tab_k.nb_items-1]);

	}	
	
	// Memory liberation
		delete_tab(z,tab_k.capacity, tab_k.nb_items);
		delete_tab(x,tab_k.capacity, tab_k.nb_items);
		delete_tab_knapsack(&tab_k);
		free(sol);


    ftime(&t1);
    cpu_time = (double)(t1.time - t0.time) + (double)(t1.millitm-t0.millitm)/1000.0;
    printf("\nCPU time : %f seconds.\n", cpu_time);

    return EXIT_SUCCESS;
}
