CC=gcc
CFLAGS=-Wall

debug:clean
	$(CC) $(CFLAGS) -g -o knapsack_problem others.c file.c main.c
	
	
debug_full: CFLAGS += -DDEBUG=1
debug_full: clean debug
	
#stable:clean
#	$(CC) $(CFLAGS) -o knapsack_problem main.c

clean:	
	@echo - Cleaning generated files
	@echo 
	rm -vfr *~ knapsack_problem
	@echo 

