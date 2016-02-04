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

int** create_tab(char* filename)
{}

