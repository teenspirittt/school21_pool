all: io.o main.o state_sort.o 
	gcc io.o main.o state_sort.o -o ../build/all

state_sort: io.o main.o state_sort.o 
	gcc io.o main.o state_sort.o -o ../build/Quest_1

state_search: io.o search.o state_sort.o state_search.o
	gcc io.o search.o state_sort.o state_search.o -o ../build/Quest_2

clear_state: io.o search.o state_sort.o state_search.o
	gcc io.o search.o state_sort.o state_search.o -o ../build/Quest_3

io.o: io.c
	gcc -c io.c

main.o: main.c
	gcc -c main.c

state_sort.o: state_sort.c
	gcc -c state_sort.c

search.o: search.c
	gcc -c search.c

state_search.o: state_search.c
	gcc -c state_search.c

clean:
	rm *.o ../build/Quest_1

leaks: 
	leaks --atExit -- ../build/Quest_1 

cpplint:
	python3 cpplint.py --extensions=c *.c

rebuild:
	$(MAKE) clean
	$(MAKE) all

.PHONY: clean all rebuild 
