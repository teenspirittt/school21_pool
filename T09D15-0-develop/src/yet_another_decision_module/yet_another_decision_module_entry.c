#include <stdio.h>
#include <stdlib.h>

#include "../data_libs/data_io.h"
#include "decision.h"
int main() {
  double *data;
  int n = 0;
  if (input(data, &n) == 1) return 1;
  data = (double *)malloc((n) * sizeof(double));
  if (input(data, &n) == 1) return 1;
  if (make_decision(data, n))
    printf("YES");
  else
    printf("NO");
}
