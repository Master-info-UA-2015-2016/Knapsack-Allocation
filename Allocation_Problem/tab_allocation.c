#include "tab_allocation.h"

void print_tab(tab_allocation * allocation) {
	
	int i, j;
	printf("Location number : %d, crates number : %d \n",allocation->nb_location, allocation->nb_crates);
	for (i = 0; i < allocation->nb_crates; ++i) {
		for (j = 0; j < allocation->nb_location; ++j) {
			printf("%d  ",allocation->tab[i][j]);
		}
		printf("\n");
	}
}

void delete_tab(int *** _tab, int nb_crates, int nb_location)
{
    int i;
    for (i= 0; i < nb_crates; ++i){
	int j;
	for (j= 0; j < nb_location; ++j){
	    free(_tab[i]);
	}
    }
}

void delete_tab_allocation(tab_allocation* allocation)
{
    delete_tab(allocation->tab, allocation->nb_crates, allocation->nb_location);
    
    free(allocation->tab);
}
