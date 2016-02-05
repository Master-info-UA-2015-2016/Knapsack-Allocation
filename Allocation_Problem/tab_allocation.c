#include "tab_allocation.h"

void display_tab(int *** tab, int nb_crates, int nb_location) {
	int i,j;
	for (i = 0; i < nb_crates; ++i) {
		for (j = 0; j < nb_location; ++j) {
			printf("%d ", (*tab)[i][j]);
		}
		printf("\n");
	}
}

void allocate_tab(int *** tab, int nb_crates, int nb_location) {
	int i;
	(*tab) =(int **)malloc(nb_crates*sizeof(int *));
	for (i = 0; i < nb_crates; ++i) {
		(*tab)[i] = (int *)malloc(nb_location*sizeof(int));
	}
}

void display_tab_allocation(tab_allocation * allocation) 
{
    printf("Location number : %d, crates number : %d \n",allocation->nb_location, allocation->nb_crates);
    display_tab(&(allocation->tab), allocation->nb_crates, allocation->nb_location);
}

void delete_tab(int ** _tab, int nb_crates, int nb_location)
{
    int i;
    for (i= 0; i < nb_crates; ++i){
	free(_tab[i]);
    }
    free(_tab);
}

void delete_tab_allocation(tab_allocation* allocation)
{
    delete_tab(allocation->tab, allocation->nb_crates, allocation->nb_location);
}
