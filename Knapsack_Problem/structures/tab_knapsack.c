#include "tab_knapsack.h"

void display_tab(int *** tab, int capacity, int nb_items) {
	int i,j;
	for (i = 0; i <= capacity; ++i) {
		for (j = 0; j < nb_items; ++j) {
			printf("%d ", (*tab)[i][j]);
		}
		printf("\n");
	}
}

void allocate_tab(int *** tab, int capacity, int nb_items) {
	int i;
	(*tab) =(int **)malloc((1+capacity)*sizeof(int *));
	for (i = 0; i <= capacity; ++i) {
		(*tab)[i] = (int *)malloc(nb_items*sizeof(int));
	}
}

void display_tab_knapsack(tab_knapsack * knapsack) 
{
	int i;
    printf("Item number : %d, capacity : %d \n",knapsack->nb_items, knapsack->capacity);
    for (i = 0; i < knapsack->nb_items; ++i) {
		printf("Item %d with size %d and profit %d \n", knapsack->items[i].id, knapsack->items[i].a, knapsack->items[i].c);
	}
}

void delete_tab(int ** _tab, int capacity, int nb_items)
{
    int i;
    for (i= 0; i <= capacity; ++i){
		free(_tab[i]);
    }
    free(_tab);
}

void delete_tab_knapsack(tab_knapsack* knapsack)
{
	free(knapsack->items);
}
