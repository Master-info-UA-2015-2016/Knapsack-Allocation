#include "others.h"

void printdebug( const char * format, ... ){   
#if DEBUG
    va_list args;

    va_start(args, format);
    vprintf(format, args);
    va_end(args);
#endif
}

int max(int n, int** values)
{
    int max= -1;
    
    if (values != NULL){
	
	int i;
	for (i = 0; i < n; ++i){
	    if ((*values)[i] > max){
		max= (*values)[i];
	    }
	}
    }else fprintf(stderr, "Error, can't find max value of an unitialized array");
    
    return max;
}