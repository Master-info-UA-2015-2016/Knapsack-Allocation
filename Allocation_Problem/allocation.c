#include "allocation.h"

void init_dynamic_optimal(tab_allocation* tab_a, int *** z, int *** x){
	int i;
	
	for (i = 0; i < tab_a->nb_crates; ++i) {
		// First column initialized with same values
		//  column of the data array first column
		(*z)[i][0] = tab_a->tab[i][0];
		(*x)[i][0] = i;
		
		// Others columns are initialized with 0
		int j;
		for (j= 1; j < tab_a->nb_location; ++j){
		    (*z)[i][j] = 0;
		    (*x)[i][j] = 0;    
		}
	}
}

void dynamic_optimal(tab_allocation* tab_a, int *** z, int *** x){
	int z_max, z_tmp, x_max;
	// Calcul for each number of crates sold (alpha), for each location (k)
	int xk, k, alpha;
	for(k= 1; k < tab_a->nb_location; ++k){
		for (alpha= 0; alpha < tab_a->nb_crates; ++alpha){
			z_max = 0; x_max = 0;
			// Calcul of each profit by number of crate sold at current location
			//  and previous ones, and selection of max one
			for (xk = 0; xk <= alpha; ++xk) {
				// Value of Zk(alpha)
				z_tmp = (*tab_a).tab[xk][k] + (*z)[alpha-xk][k-1];
				
				// If value is greater than current max value,
				//  it overrides current max value 
				if (z_tmp >= z_max){
					z_max = z_tmp;
					x_max= xk;
				}
			}
			// Found values stored in arrays
			(*z)[alpha][k] = z_max;
			(*x)[alpha][k] = x_max;
		}
	}
}

void optimal_solution(int *** x, int ** solution, int alpha, int k) {
	if (k>=0){
		int xk = (*x)[alpha][k];
		(*solution)[k] = xk;
		optimal_solution(x, solution, alpha-xk, k-1);
	}
}
