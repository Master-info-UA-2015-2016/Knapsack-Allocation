#include <stdio.h>
#include <stdlib.h>

#include "file.h"
#include "tab_allocation.h"
#include "allocation.h"


void display_tab(int *** tab, int nb_crates, int nb_location) {
	int i,j;
	for (i = 0; i < nb_crates; ++i) {
		for (j = 0; j < nb_location; ++j) {
			printf("%d ", (*tab)[i][j]);
		}
		printf("\n");
	}
}

void allocate_tab(int *** tab, int nb_crates, int nb_location) {
	int i;
	(*tab) =(int **)malloc(nb_crates*sizeof(int *));
	for (i = 0; i < nb_crates; ++i) {
		(*tab)[i] = (int *)malloc(nb_location*sizeof(int));
	}
}

int main(int argc, char **argv) {
	tab_allocation allocation;
	int ** z;
	int ** x;
	allocation = *(create_tab("Allocation.txt"));
	print_tab(&allocation);
	/*z = (int **)malloc( (allocation.nb_crates)*sizeof(int *));
	for (i = 0; i < allocation.nb_crates; ++i) {
		z[i] = (int *)malloc( (allocation.nb_location)*sizeof(int));
	}*/
	
	/*x = (int **)malloc( (allocation.nb_crates)*sizeof(int *));
	for (i = 0; i < allocation.nb_crates; ++i) {
		x[i] = (int *)malloc( (allocation.nb_location)*sizeof(int));
	}*/
	allocate_tab(&z, allocation.nb_crates, allocation.nb_location);
	allocate_tab(&x, allocation.nb_crates, allocation.nb_location);
	init_dynamic_optimal(&allocation, &z, &x);
	
	display_tab(&z, allocation.nb_crates, allocation.nb_location);
	display_tab(&x, allocation.nb_crates, allocation.nb_location);

	/*for (i = 0; i < allocation.nb_crates; ++i) {
		for (j = 0; j < allocation.nb_location; ++j) {
			printf("%d ", z[i][j]);
		}
		printf("\n");
	}*/
	
	/*for (i = 0; i < allocation.nb_crates; ++i) {
		for (j = 0; j < allocation.nb_location; ++j) {
			printf("%d ", x[i][j]);
		}
		printf("\n");
	}*/
	return 0;
}
