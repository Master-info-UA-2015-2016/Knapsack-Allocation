#include "file.h"

int read_first_line(FILE* file, int * nb_location, int * nb_crates)
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
	    *nb_location = atoi(values);
	
	    // next value
	    values = strtok (NULL, " ");
	}
	else {
	    fprintf(stderr, "No location value");
	    return 0;
	}
	
	if (values != NULL){
// 	    printdebug("2nb value %s\n", values);
	    *nb_crates = atoi(values);
	    // useless to get next value
	}
	else {
	    fprintf(stderr, "No crates number");
	    return 0;
	}
	
	return 1;
    } else { return 0;}
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

void print_tab(tab_allocation * allocation) {
	
	int i, j;
	printf("Location number : %d, crates number : %d \n",allocation->nb_location, allocation->nb_crates);
	for (i = 0; i < allocation->nb_crates; ++i) {
		for (j = 0; j < allocation->nb_location; ++j) {
			printf("%d  ",allocation->tab[i][j]);
		}
		printf("\n");
	}
}
