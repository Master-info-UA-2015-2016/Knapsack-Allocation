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

void delete_tab(tab_allocation* allocation)
{
    int i;
    for (i= 0; i < allocation->nb_crates; ++i){
	int j;
	for (j= 0; j < allocation->nb_location; ++j){
	    free(allocation->tab[i]);
	}
    }
    free(allocation->tab);
}