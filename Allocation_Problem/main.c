#include <stdio.h>
#include <stdlib.h>
#include <sys/timeb.h>

#include "file.h"
#include "tab_allocation.h"
#include "allocation.h"

int main(int argc, char **argv) {
    
    struct timeb t0, t1;    /* Timers */
    double cpu_time;        /* Time */
    
    ftime(&t0);

    if(argc != 2)
    {
	fprintf(stderr, "\nPlease, call the program with an argument, that is the instance file name.\n");
	printf("\nexit(EXIT_FAILURE) mis en commentaire, enlever le commentaire\n");
// 	exit(EXIT_FAILURE);
    }

	tab_allocation* allocation;
	int ** z;
	int ** x;
	int * sol;
	int i;
	allocation = create_tab("Allocation.txt");
	display_tab_allocation(allocation);
	printf("\n");

	// Creation of arrays Z and X
	allocate_tab(&z, allocation->nb_crates, allocation->nb_location);
	allocate_tab(&x, allocation->nb_crates, allocation->nb_location);
	
	// Initialization of Z and X according to data
	init_dynamic_optimal(allocation, &z, &x);
	// Search of maximum profit by number f crate by location, stored into Z and X
	dynamic_optimal(allocation, &z, &x);
	
	printf("\nArray of profits\n");
	display_tab(&x, allocation->nb_crates, allocation->nb_location);
	printf("\nArray of number of crates sold to maximize profit\n");
	display_tab(&z, allocation->nb_crates, allocation->nb_location);
	printf("\n");
	
	sol = (int*)malloc(allocation->nb_location*sizeof(int));
	optimal_solution(&x, &sol, allocation->nb_crates-1, allocation->nb_location-1);
	
	printf("Number of crates solde by location :\n");
	for (i = 0; i < allocation->nb_location; ++i){
	     printf("%d ;", sol[i]);
	}
	
	printf("\nOptimal solution : %d\n", z[allocation->nb_crates-1][allocation->nb_location-1] );
	
	
	// Memory liberation
	delete_tab(z, allocation->nb_crates, allocation->nb_location);
	delete_tab(x, allocation->nb_crates, allocation->nb_location);
	delete_tab_allocation(allocation);
	free(allocation);


    ftime(&t1);
    cpu_time = (double)(t1.time - t0.time) + (double)(t1.millitm-t0.millitm)/1000.0;
    printf("\nCPU time : %f seconds.\n", cpu_time);

    return EXIT_SUCCESS;
}
