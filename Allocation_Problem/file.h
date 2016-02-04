#ifndef FILE_H
#define FILE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "others.h"
#include "tab_allocation.h"

/**
 */
int read_first_line(FILE* file, int * nb_location, int * nb_crates);

/**
 */
tab_allocation* create_tab(char* filename);


#endif
