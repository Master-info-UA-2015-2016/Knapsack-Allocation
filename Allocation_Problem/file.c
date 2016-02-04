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

tab_allocation* create_tab(char* filename)
{
    tab_allocation* tab_a = NULL;
    
    // Reading
    FILE *file;
    file= fopen(filename,"r");
    
    if (file != NULL)
    {
	char line[31];
	
	tab_a= (tab_allocation*)malloc(sizeof(tab_allocation));
	
	if ( read_first_line(file, &(tab_a->nb_location), &(tab_a->nb_crates)) ){
	    tab_a->tab= (int**)malloc(tab_a->nb_crates*sizeof(int*));
	    
	    int i;
	    for (i= 0; i < tab_a->nb_crates; ++i){
		tab_a->tab[i]= (int*)malloc(tab_a->nb_location*sizeof(int));
		
		if (fgets(line, 30, file) == NULL){
		    fprintf(stderr, "File empty");
		    return 0;
		}
		
		// Value reading
		int j;
		for (j= 0; j < 3; ++j){
		    char* values= strtok(line, " ");
		    if (values != NULL){
			printdebug ("%d e location profit for %d crates : %s\n", j, i, values);
			tab_a->tab[i][j]= atoi(values);
			// next value
			values = strtok (NULL, " ");
		    } else {
			fprintf(stderr, "No id");
			return 0;
		    }
		}
		
	    }
	    
	} else {
	    fprintf(stderr, "Error while reading first line, impossible to continue");
	}
	
    } else {
	fprintf(stderr, "Allocation table impossible to create because file can't be read");
	return NULL;
    }
    return tab_a;
}

