#include "file.h"

int read_first_line(FILE* file)
{
    /*char line[31];
    
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
    } else { return 0;}*/ return 0;
}

int** create_tab(char* filename)
{
	int** tab;
    /*char line[31];
    
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
    }*/
	return tab;
}

