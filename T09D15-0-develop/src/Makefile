all: main_executable_module.o data_io.o data_sort.o data_stat.o data_process.o decision.o
	gcc  main_executable_module.o data_io.o data_sort.o data_stat.o data_process.o decision.o -o ../build/Quest3

main_executable_module.o: ./main_executable_module/main_executable_module.c 
	gcc -c ./main_executable_module/main_executable_module.c 

data_io.o: ./data_libs/data_io.c
	gcc -c ./data_libs/data_io.c

data_sort.o: ./data_libs/data_sort.c
	gcc -c ./data_libs/data_sort.c

data_stat.o: ./data_libs/data_stat.c
	gcc -c ./data_libs/data_stat.c

data_process.o: ./data_module/data_process.c
	gcc -c ./data_module/data_process.c

decision.o: ./yet_another_decision_module/decision.c
	gcc -c ./yet_another_decision_module/decision.c

data_stat.a: ./data_libs/data_stat.c
	ar r data_stat.a data_stat.o

data_process.so: ./data_module/data_process.o ./data_libs/data_stat.o
	gcc -shared -o data_process.so data_process.o ./data_libs/data_stat.o
	
clean:
	rm *.o *.a *.so 

build_with_static: main_executable_module.o data_io.o data_sort.o data_stat.a data_process.o decision.o 
	gcc  main_executable_module.o data_io.o data_sort.o data_stat.a data_process.o decision.o -o ../build/Quest5
	
build_with_dynamic: main_executable_module.o data_io.o data_sort.o data_stat.o data_process.o data_process.so decision.o 
	gcc main_executable_module.o data_io.o data_sort.o data_stat.o data_process.o data_process.so decision.o -o ../build/Quest6

build_with_macro: main_executable_module.o data_io.o data_sort.o data_stat.o data_process.o decision.o
	gcc  -D flag main_executable_module.o data_io.o data_sort.o data_stat.o data_process.o decision.o -o ../build/Quest3

rebuild:
	$(MAKE) clean
	$(MAKE) all

.PHONY: clean all rebuild