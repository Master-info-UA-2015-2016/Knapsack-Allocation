#include "file.h"

boolean read_first_line(FILE* file, int* items_nb, int* capacity)
{
    char line[31];
    
    if (file != NULL)
    {
	if (fgets(line, 30, file) == NULL){
	    fprintf(stderr, "File empty");
	    return 0;
	}

	char* values= strtok (line," ");
	if (values != NULL){
// 	    printdebug("1st value %s\n", values);
	    *items_nb= atoi(values);
	
	    // next value
	    values = strtok (NULL, " ");
	}
	else {
	    fprintf(stderr, "No capacity value");
	    return 0;
	}
	
	if (values != NULL){
// 	    printdebug("2nb value %s\n", values);
	    *capacity= atoi(values);
	    // useless to get next value
	}
	else {
	    fprintf(stderr, "No items number");
	    return 0;
	}
	
	return 1;
    } else { return 0;}
}

tab_items init_items(FILE* file, int items_nb)
{
    char line[31];
    
    if (file != NULL)
    {    
	tab_items items= (tab_items)malloc(items_nb*sizeof(item));
	
	int i;
	for (i= 0; i < items_nb; ++i){
	    if (fgets(line, 30, file) == NULL){
		fprintf(stderr, "File empty");
		return 0;
	    }
	    
	    // Value reading
	    char* values= strtok(line, " ");
	    if (values != NULL){
		printdebug ("item id : %s\n", values);	    
		items[i].id=	atoi(values);
		// next value
		values = strtok (NULL, " ");
	    } else {
		fprintf(stderr, "No id");
		return 0;
	    }
	    
	    if (values != NULL){
		printdebug("size : %s\n", values);
		items[i].a=   atoi(values);
		// next value
		values = strtok (NULL, " ");
	    } else {
		fprintf(stderr, "No size");
		return 0;
	    }
	    
	    if (values != NULL){
		printdebug("cost : %s\n", values);
		items[i].c=   atoi(values);
		// useless to get next value
	    } else {
		fprintf(stderr, "No cost");
		return 0;
	    }
	    
	    printdebug("DEBUG : Item [%d] created : size %d, cost %d\n", items[i].id, items[i].a, items[i].c);
	    
	}
	return items;
	
    } else {
	fprintf(stderr, "Items creation impossible because file can't be read");
	return NULL;
    }
}

void loadInstance(char* filename, int *n, int *b, item **it)
{
/* TO COMPLETE */
/* DONE */

// Reading
    FILE *file;
    file= fopen(filename,"r");
    
    if (file != NULL){
	// File record and instanciation of items 
	if (read_first_line(file, n, b)){
	    *it= init_items(file, *n);
	}
	else {
	    fprintf(stderr, "First line reading impossible");
	    // verification needed after call of loadInstance to ensure
	    // there was not any problem during reading
	}
    }
    else {
	fprintf(stderr, "File reading impossible");
	// verification needed after call of loadInstance to ensure
	// there was not any problem during reading
    }
//     printdebug("Je sors de loadInstance\n");
}