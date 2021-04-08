CC = gcc -Wall
PROG = puissance4

all : $(PROG)

$(PROG) : aGagne.o puissance4.o
	gcc $^ -o $@

aGagne.o : aGagne.c aGagne.h
	$(CC) -c aGagne.c -o $@

puissance4.o : puissance4.c
	$(CC) -c $^ -o $@
