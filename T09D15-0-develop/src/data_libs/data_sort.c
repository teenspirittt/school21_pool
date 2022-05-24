#include "data_sort.h"

void sort(double *data, int n) {
  int tmp;
  for (int i = 0; i < n - 1; i++)
    for (int j = 0; j < n - i - 1; j++)
      if (data[j] > data[j + 1]) {
        tmp = data[j];
        data[j] = data[j + 1];
        data[j + 1] = tmp;
      }
}
