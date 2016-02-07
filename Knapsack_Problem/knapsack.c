#include "knapsack.h"

void init_dynamic_optimal(tab_knapsack* tab_k, int *** z, int *** x){
	int i,j;
	
	for (i = 0; i <= tab_k->capacity; ++i) {
		// First column initialized with same values
		//  column of the data array first column
		for (j = 0; j < tab_k->nb_items; ++j) {
			(*z)[i][j] = 0;
			(*x)[i][j] = 0;
		}
	}
	
	for (i = tab_k->items[0].a; i <= tab_k->capacity; ++i) {
		(*z)[i][0] = tab_k->items[0].c;
		(*x)[i][0] = 1;
	}
}

void dynamic_optimal(tab_knapsack* tab_k, int *** z, int *** x){
	int k, xk, max, z_tmp, x_tmp, tmp;
	int alpha;

	// Calcul for each number of crates sold (alpha), for each location (k)
	init_dynamic_optimal(tab_k, z, x);
	for(k= 1; k < tab_k->nb_items; ++k){
		for (alpha= 1; alpha <= tab_k->capacity; ++alpha){
			max = 0;
			z_tmp = 0;
			x_tmp = 0;
			// Calcul of each profit by number of crate sold at current location
			//  and previous ones, and selection of max one
			for (xk = 0; xk <= 1; ++xk) {
				tmp = alpha-(xk*(tab_k->items[k].a));
				if (tmp < 0) 
					z_tmp = 0;
				else z_tmp = (tab_k->items[k].c)*xk + (*z)[tmp][k-1];
				// If value is greater than current max value,
				//  it overrides current max value 
				if (z_tmp >= max){
					max = z_tmp;
					if (tmp < 0) x_tmp = 0;
					else x_tmp= xk;
				}

			}
			// Found values stored in arrays
			(*z)[alpha][k] = max;
			(*x)[alpha][k] = x_tmp;
		}
    }
}

void optimal_solution(tab_knapsack *tab_k, int *** x, int ** solution, int alpha, int k) {
	if (k >= 0){
		int xk = (*x)[alpha][k];
		(*solution)[k] = xk;
		if (xk == 1) 
			optimal_solution(tab_k, x, solution, alpha-(tab_k->items[k].a), k-1);
		else optimal_solution(tab_k, x, solution, alpha, k-1);
	}
}
