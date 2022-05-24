#ifndef SRC_IO_H_
#define SRC_IO_H_

#define ERROR 0
#include <stdio.h>
int input(char **str, int *size);
void output(FILE *f);
void add_tape(FILE *fp);
void search_input(char **str, int *size);

#endif  // SRC_IO_H_
