#include "allocation.h"

void init_dynamic_optimal(tab_allocation* tab_a, int *** z, int *** x){
	int i;
	
	for (i = 0; i < tab_a->nb_crates; ++i) {
		(*z)[i][0] = tab_a->tab[i][0];
		(*x)[i][0] = i;
		
		// Initialization of tabs
		int j;
		for (j= 1; j < tab_a->nb_location; ++j){
		    (*z)[i][j] = 0;
		    (*x)[i][j] = 0;    
		}
	}
}

void dynamic_optimal(tab_allocation* tab_a, int *** z, int *** x){
    int k;
    int alpha;
    for(k= 1; k < tab_a->nb_location; ++k){
	
	for (alpha= 1; alpha < tab_a->nb_crates; ++alpha){
	    // Zk(alpha) = max (Ck(Xk) + *(z)[alpha- ???][k-1] )
// 	    *(z)[alpha][k]= 0;
	}
	
    }
	
}
