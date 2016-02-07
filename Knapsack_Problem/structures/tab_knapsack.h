#ifndef TAB_KNAPSACK_H
#define TAB_KNAPSACK_H

#include <stdio.h>
#include <stdlib.h>
#include "./item.h"

struct tab_knapsack {
	int capacity;
	int nb_items;
	tab_items items;
};
typedef struct tab_knapsack tab_knapsack;


void allocate_tab(int *** tab, int capacity, int nb_items);

void display_tab(int *** tab, int capacity, int nb_items);

void delete_tab(int ** _tab, int capacity, int nb_items);

/**
 */
void display_tab_knapsack(tab_knapsack * knapsack);

void delete_tab_knapsack(tab_knapsack* knapsack);

#endif
