#ifndef KNAPSACK_H
#define KNAPSACK_H

#include "tab_knapsack.h"

void init_dynamic_optimal(tab_knapsack* tab_k, int *** z, int *** x);

void dynamic_optimal(tab_knapsack* tab_k, int *** z, int *** x);

void optimal_solution(int *** x, int ** solution, int alpha, int k);

#endif
