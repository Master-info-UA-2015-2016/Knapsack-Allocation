#include <stdio.h>
#include <stdlib.h>
#include "file.h"



int main(int argc, char **argv) {
	tab_allocation allocation;
	allocation = *(create_tab("Allocation.txt"));
	print_tab(&allocation);
	return 0;
}
