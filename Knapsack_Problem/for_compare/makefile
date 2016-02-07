CC=gcc
CFLAGS=-Wall
LDFLAGS= -lm
EXEC= PROG
SRC= main.c
FILES_DIR=resources/
OBJ =$(SRC:.c=.o)

all: $(EXEC)

PROG: $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm -rf *.o $(FILES_DIR)*.data.ilp $(FILES_DIR)*.cplex

mrproper: clean
	rm -rf $(EXEC)
