#include "state_sort.h"

#include <stdio.h>
#include <stdlib.h>

void bubble_sort(FILE *fp) {
  int *data1 = (int *)malloc(8 * sizeof(int));
  int *data2 = (int *)malloc(8 * sizeof(int));
  int size = get_size(fp) / 8;
  for (int i = 0; i < size - 1; i++) {
    for (int j = 0; j < size - i - 1; j++) {
      fseek(fp, j * 8 * sizeof(int), SEEK_SET);
      fread(data1, sizeof(int), 8, fp);
      fread(data2, sizeof(int), 8, fp);
      if (cmp(data1, data2) > 0) {
        swap(fp, data1, data2, j, j + 1);
      }
    }
  }
  free(data1);
  free(data2);
}

int get_size(FILE *fp) {
  int num;
  int size = 0;
  while (!feof(fp)) {
    for (int i = 0; i < 8; ++i) {
      fread(&num, sizeof(int), 1, fp);
      size++;
    }
  }
  return size;
}

int cmp(int *a, int *b) {
  int flag = a[0] - b[0];
  for (int i = 1; i < 8 && flag == 0; i++)
    if (flag == 0) flag = a[i] - b[i];
  return flag;
}

void swap(FILE *fp, int *data1, int *data2, int curr, int next) {
  fseek(fp, curr * 8 * sizeof(int), SEEK_SET);
  fwrite(data2, sizeof(int), 8, fp);
  fseek(fp, next * 8 * sizeof(int), SEEK_SET);
  fwrite(data1, sizeof(int), 8, fp);
}
