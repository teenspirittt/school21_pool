#include <stdio.h>
#include <stdlib.h>

#include "../data_libs/data_io.h"
#include "data_process.h"

int main() {
  int n = 0;
  double *data;
  if (input(data, &n) == 1) return 1;
  data = (double *)malloc((n) * sizeof(double));
  if (input(data, &n) == 1) return 1;
  if (normalization(&data, n)) {
    output(data, n);
  } else {
    printf("ERROR");
  }
  return 0;
}
