#ifndef KNAPSACK_H
#define KNAPSACK_H

#include "./structures/tab_knapsack.h"

/**
 * Initialisation of arrays, before using algorithm
 */
void init_dynamic_optimal(tab_knapsack* tab_k, int *** z, int *** x);

/*
 * Calcul of profit by number of crates sold by location, results stored in z and x
 */
void dynamic_optimal(tab_knapsack* tab_k, int *** z, int *** x);

/*
 * Give number of crates sold by location to obtain maximum profit
 */
void optimal_solution(tab_knapsack *tab_k, int *** x, int ** solution, int alpha, int k);

#endif
