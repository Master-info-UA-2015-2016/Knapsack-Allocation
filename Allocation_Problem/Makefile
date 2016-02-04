CC=gcc
CFLAGS="-Wall"

debug:clean
	$(CC) $(CFLAGS) -g -o allocation_problem main.c file.c
stable:clean
	$(CC) $(CFLAGS) -o allocation_problem main.c file.c
clean:
	rm -vfr *~ allocation_problem
