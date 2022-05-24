#ifndef SRC_STATE_SORT_H_
#define SRC_STATE_SORT_H_
#include <stdio.h>
void bubble_sort(FILE *fp);
int get_size(FILE *fp);
int cmp(int *a, int *b);
void swap(FILE *fp, int *data1, int *data2, int curr, int next);

#endif  // SRC_STATE_SORT_H_
