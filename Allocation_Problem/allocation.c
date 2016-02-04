#include "allocation.h"

int dynamic_optimal(tab_allocation* tab_a, int r, int alpha){
    max( Xk € {0, ..., alpha}
	Ck(Xk) + dynamic_optimal(tab_a, k-1, alpha- Zk));
}