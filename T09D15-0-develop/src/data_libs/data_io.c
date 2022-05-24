#include "data_io.h"

#include <stdio.h>
#include <stdlib.h>

#include "../data_module/data_process.h"

int input(double *data, int *n) {
  int error = 0;
  char c;
  if (*n == 0) {
    if (error == 0) {
      if (scanf("%d", n) != 1) {
        if (error == 0) error_print;
        error = ERROR;
      }
      if (error == 0) {
        if ((scanf("%c", &c) != 0) && (c != '\n') && (c != ' ')) {
          if (error == 0) error_print;
          error = ERROR;
        }
      }
      if (error == 0)
        return 0;
      else
        return error;
    }
  }
  if (error == 0) {
    for (int i = 0; i < *n; ++i) {
      if (scanf("%lf", &data[i]) != 1) {
        if (error == 0) error_print;
        error = ERROR;
      }
      if ((scanf("%c", &c) != 0) && (c != '\n') && (c != ' ')) {
        if (error == 0) error_print;
        error = ERROR;
      }
    }
  }
  return error;
}

void output(double *data, int n) {
  for (int i = 0; i < n; ++i) {
    if (i != (n - 1)) {
      printf("%lf ", data[i]);
    } else {
      printf("%lf", data[i]);
    }
  }
}
