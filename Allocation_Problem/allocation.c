#include "allocation.h"

void init_dynamic_optimal(tab_allocation* tab_a, int *** z, int *** x){
	int i;
	
	for (i = 0; i < tab_a->nb_crates; ++i) {
		(*z)[i][0] = tab_a->tab[i][0];
		(*x)[i][0] = i;
	}
}

void dynamic_optimal(tab_allocation* tab_a, int *** z, int *** x){
	
	
}
