all: dmanager_module.o stack_test.o stack.o
	gcc dmanager_module.o stack_test.o stack.o -o ../build/all

dmanager_module.o: dmanager_module.c
	gcc -c dmanager_module.c

stack_test.o: stack_test.c
	gcc -c stack_test.c

stack.o: stack.c
	gcc -c stack.c	

stack_test: stack_test.o stack.o
	gcc stack_test.o stack.o -o ../build/Quest_3

door_struct: dmanager_module.o  
	gcc dmanager_module.o -o ../build/Quest_1

clean: 
	rm *.o ../build/Quest_1 ../build/Quest_3

rebuild:
	$(MAKE) clean
	$(MAKE) all

.PHONY: clean all rebuild stack_test
