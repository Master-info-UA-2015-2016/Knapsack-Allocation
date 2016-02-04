#ifndef TAB_ALLOCATION_H
#define TAB_ALLOCATION_H

#include <stdio.h>

struct tab_allocation {
	int nb_location;
	int nb_crates;
	int ** tab;
};
typedef struct tab_allocation tab_allocation;


/**
 */
void print_tab(tab_allocation * allocation);

#endif