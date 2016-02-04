#ifndef FILE_H
#define FILE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>



struct tab_allocation {
	int nb_location;
	int nb_crates;
	int ** tab;
};
typedef struct tab_allocation tab_allocation;

/**
 */
int read_first_line(FILE* file, int * nb_location, int * nb_crates);

/**
 */
tab_allocation create_tab(char* filename);

#endif
