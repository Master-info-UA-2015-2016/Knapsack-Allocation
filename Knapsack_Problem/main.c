#include <stdio.h>
#include <stdlib.h>
#include "file.h"
#include "knapsack.h"

int main(int argc, char **argv) {
	tab_knapsack tab_k;
	int ** z;
	int ** x;
	loadInstance("DEFAYE_Johan.txt", &(tab_k.nb_items), &(tab_k.capacity), &(tab_k.items));
	display_tab_knapsack(&tab_k);
	allocate_tab(&z, tab_k.capacity, tab_k.nb_items);
	allocate_tab(&x, tab_k.capacity, tab_k.nb_items);
	init_dynamic_optimal(&tab_k, &z, &x);
	dynamic_optimal(&tab_k, &z, &x);
	display_tab(&z, tab_k.capacity, tab_k.nb_items);
	display_tab(&x, tab_k.capacity, tab_k.nb_items);
    return 0;
}
