CC=gcc
CFLAGS="-Wall"

debug:clean
	$(CC) $(CFLAGS) -g -o allocation_problem others.c file.c main.c
	
		
debug_full: CFLAGS += -DDEBUG=1
debug_full: clean debug
	
#stable:clean
#	$(CC) $(CFLAGS) -o allocation_problem main.c file.c

clean:
	@echo - Cleaning generated files
	@echo 
	rm -vfr *~ allocation_problem
	@echo 