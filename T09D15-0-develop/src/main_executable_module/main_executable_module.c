#include <stdio.h>
#include <stdlib.h>

#include "../data_libs/data_io.h"
#include "../data_libs/data_sort.h"
#include "../data_module/data_process.h"
#include "../yet_another_decision_module/decision.h"

int main() {
  int n = 0;
  double *data;
  printf("LOAD DATA...\n");
  if (input(data, &n) == 1) return 1;
  data = (double *)malloc((n) * sizeof(double));
  if (input(data, &n) == 1) return 1;
  printf("RAW DATA:\n\t");
  output(data, n);
  printf("\nNORMALIZED DATA:\n\t");
  normalization(&data, n);
  output(data, n);
  printf("\nSORTED NORMALIZED DATA:\n\t");
  sort(data, n);
  output(data, n);
  printf("\nFINAL DECISION:\n\t");
  make_decision(data, n);
  output(data, n);
}
