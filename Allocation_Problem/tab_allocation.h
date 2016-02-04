#ifndef TAB_ALLOCATION_H
#define TAB_ALLOCATION_H

#include <stdio.h>
#include <stdlib.h>

struct tab_allocation {
	int nb_location;
	int nb_crates;
	int ** tab;
};
typedef struct tab_allocation tab_allocation;


void allocate_tab(int *** tab, int nb_crates, int nb_location);

void display_tab(int *** tab, int nb_crates, int nb_location);

void delete_tab(int ** _tab, int nb_crates, int nb_location);

/**
 */
void display_tab_allocation(tab_allocation * allocation);

void delete_tab_allocation(tab_allocation* allocation);

#endif