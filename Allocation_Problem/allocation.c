#include "allocation.h"

void init_dynamic_optimal(tab_allocation* tab_a, int *** z, int *** x){
	int i;
	
	for (i = 0; i < tab_a->nb_crates; ++i) {
		(*z)[i][0] = tab_a->tab[i][0];
		(*x)[i][0] = i;
	}
}

// Zk(alpha) = max (Ck(Xk) + *(z)[alpha- ???][k-1] )
//*(z)[alpha][k]= 0;

void dynamic_optimal(tab_allocation* tab_a, int *** z, int *** x){
    int k, xk, max, z_tmp, x_tmp;
    int alpha;
    for(k= 1; k < tab_a->nb_location; ++k){
		for (alpha= 1; alpha < tab_a->nb_crates; ++alpha){
			max = 0;
			z_tmp = 0;
			x_tmp = 0;
			for (xk = 0; xk <= alpha; ++xk) {
				z_tmp = (*tab_a).tab[xk][k] + (*z)[alpha-xk][k-1];
				if (z_tmp >= max){
					 max = z_tmp;
					 x_tmp= xk;
				 }
			}
			(*z)[alpha][k] = max;
			(*x)[alpha][k] = x_tmp;
		}
    }
}
