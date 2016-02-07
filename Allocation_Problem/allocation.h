#ifndef ALLOCATION_H
#define ALLOCATION_H

#include "file.h"

/**
 * Initialisation of arrays, before using algorithm
 */
void init_dynamic_optimal(tab_allocation* tab_a, int *** z, int *** x);

/*
 * Calcul of profit by number of crates sold by location, results stored in z and x
 */
void dynamic_optimal(tab_allocation* tab_a, int *** z, int *** x);

/*
 * Give number of crates sold by location to obtain maximum profit
 */
void optimal_solution(int *** x, int ** solution, int alpha, int k);

#endif
