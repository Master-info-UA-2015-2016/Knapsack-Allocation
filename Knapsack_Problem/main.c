#include <stdio.h>
#include <stdlib.h>
#include <sys/timeb.h>

#include "file.h"
#include "knapsack.h"

int main(int argc, char **argv) {

    struct timeb t0, t1;    /* Timers */
    double cpu_time;        /* Time */
    
    ftime(&t0);
    
	tab_knapsack tab_k;
	int ** z;
	int ** x;
	loadInstance("./resources/exemple.txt", &(tab_k.nb_items), &(tab_k.capacity), &(tab_k.items));
	display_tab_knapsack(&tab_k);
	allocate_tab(&z, tab_k.capacity, tab_k.nb_items);
	allocate_tab(&x, tab_k.capacity, tab_k.nb_items);
	init_dynamic_optimal(&tab_k, &z, &x);
	dynamic_optimal(&tab_k, &z, &x);
	display_tab(&z, tab_k.capacity, tab_k.nb_items);
	display_tab(&x, tab_k.capacity, tab_k.nb_items);
	
	delete_tab(z,tab_k.capacity, tab_k.nb_items);
	delete_tab(x,tab_k.capacity, tab_k.nb_items);
	delete_tab_knapsack(&tab_k);
	
	
	// Memory liberation
	


    ftime(&t1);
    cpu_time = (double)(t1.time - t0.time) + (double)(t1.millitm-t0.millitm)/1000.0;
    printf("\nCPU time : %f seconds.\n", cpu_time);

    return EXIT_SUCCESS;
}
