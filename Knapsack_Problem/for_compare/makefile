CC=gcc
CFLAGS=-Wall
LDFLAGS= -lm
EXEC= PROG
SRC= main.c
SRCGLPSOL= ilp.txt
MODELGLPSOL= mathprog.txt
OBJ =$(SRC:.c=.o)

all: $(EXEC)

PROG: $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm -rf *.o

mrproper: clean
	rm -rf $(EXEC)
