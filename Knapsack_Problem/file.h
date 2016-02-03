#ifndef FILE_H
#define FILE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "./structures/item.h"
#include "./structures/queue.h"
#include "./structures/tree.h"
#include "others.h"

typedef int boolean;

typedef item* tab_items;

/**
 */
boolean read_first_line(FILE* file, int* items_nb, int* capacity_nb);

/**
 */
tab_items init_items(FILE* file, int items_nb);

/*********************************************************/
/*                     loadInstance                      */
/*********************************************************/
/* This function opens file *filename, reads *n, the     */
/* number of items, *b the knapsack capacity, and        */
/* allocates memory for *it, an array of *n item data    */
/* structures.                                           */
/*********************************************************/
void loadInstance(char* filename, int *n, int *b, item **it);

#endif