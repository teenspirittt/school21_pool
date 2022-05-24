CC = gcc
BLD = ../build
INP = input_module
CFLAG = -Wextra  -Wall -Werror
OBJ = *.o

all: graph.o input_module.o all_structure.o plotting.o
	$(CC) -o graph.o input_module.o all_structure.o plotting.o -o ../build/main

graph.o: graph.c
	$(CC) -c $(CFLAG) graph.c

input_module.o: input_module.c
	$(CC) -c $(CFLAG) input_module.c

all_structure.o:all_structure.c
	$(CC) -c $(CFLAG) all_structure.c

plotting.o: plotting.c
	$(CC) -c $(CFLAG) plotting.c

clean:
	rm *.o Q1