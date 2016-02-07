#include <stdio.h>
#include <stdlib.h>
#include "file.h"
#include "knapsack.h"

int main(int argc, char **argv) {
	tab_knapsack tab_k;
	int ** z;
	int ** x;
	int * sol;
	int i;

	if (argc != 2) {
		fprintf(stderr, "\nPlease, call the program with only one argument, that is the items file name.\n");
		exit(EXIT_FAILURE);
	}
	else {
		loadInstance(argv[1], &(tab_k.nb_items), &(tab_k.capacity), &(tab_k.items));
		
		allocate_tab(&z, tab_k.capacity, tab_k.nb_items);
		allocate_tab(&x, tab_k.capacity, tab_k.nb_items);
		sol = (int *)malloc((tab_k.nb_items)*sizeof(int));

		dynamic_optimal(&tab_k, &z, &x);
		optimal_solution(&tab_k, &x, &sol, tab_k.capacity, tab_k.nb_items-1);
		printf("\nItem in the knapsack : \n");
		for (i = 0; i < tab_k.nb_items; ++i) {
			if (sol[i] == 1) printf("%d ", i+1);
		}	
		printf("\nOptimal profit is %d \n", z[tab_k.capacity][tab_k.nb_items-1]);
		delete_tab(z,tab_k.capacity, tab_k.nb_items);
		delete_tab(x,tab_k.capacity, tab_k.nb_items);
		delete_tab_knapsack(&tab_k);
		free(sol);
	}
	
    return 0;
}
