all: s21_string_test.o s21_string.o
	gcc s21_string_test.o s21_string.o -o ../build/Quest3

s21_string_test.o: s21_string_test.c
	gcc -c s21_string_test.c

s21_string.o: s21_string.c
	gcc -c s21_string.c

test_len1:s21_string_test.o s21_string.o
	gcc -D test_len s21_string_test.o s21_string.o -o ../build/test_len

test_cmp1:s21_string_test.o s21_string.o
	gcc -D test_cmp s21_string_test.o s21_string.o -o ../build/test_cmp

test_cpy1:s21_string_test.o s21_string.o
	gcc -D test_cpy s21_string_test.o s21_string.o -o ../build/test_cpy

test_cat1:s21_string_test.o s21_string.o
	gcc -D test_cat s21_string_test.o s21_string.o -o ../build/test_cat

test_chr1:s21_string_test.o s21_string.o
	gcc -D test_chr s21_string_test.o s21_string.o -o ../build/test_chr

test_str1:s21_string_test.o s21_string.o
	gcc -D test_str s21_string_test.o s21_string.o -o ../build/test_str

clean:
	rm *.o

rebuild:
	$(MAKE) clean
	$(MAKE) all

.PHONY: clean all rebuild

