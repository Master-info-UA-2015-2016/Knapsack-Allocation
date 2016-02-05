#ifndef ALLOCATION_H
#define ALLOCATION_H

#include "file.h"

void init_dynamic_optimal(tab_allocation* tab_a, int *** z, int *** x);

void dynamic_optimal(tab_allocation* tab_a, int *** z, int *** x);

void optimal_solution(int *** x, int ** solution, int alpha, int k);

#endif
