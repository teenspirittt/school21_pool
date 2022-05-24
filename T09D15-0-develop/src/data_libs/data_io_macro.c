#include "data_io_macro.h"

#include <stdio.h>
#include <stdlib.h>

#include "../data_module/data_process.h"

int input_int(int *data, int *n) {
  int error = 0;
  char c;
  if (*n == 0) {
    if (error == 0) {
      if (scanf("%d", n) != 1) {
        if (error == 0) {
          error_print;
        }
        error = ERROR;
      }
      if (error == 0) {
        if ((scanf("%c", &c) != 0) && (c != '\n') && (c != ' ')) {
          if (error == 0) {
            error_print;
          }
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

int input_float(float *data, int *n) {
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
          if (error == 0) {
            error_print;
          }
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

int input_double(double *data, int *n) {
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
          if (error == 0) {
            error_print;
          }
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

#define input(data, n)             \
  _Generic((DATA, N), int          \
           : input_int, float      \
           : input_float, double   \
           : input_double, default \
           : input_int)(DATA)

void output_int(int *data, int n) {
  for (int i = 0; i < n; ++i) {
    if (i != (n - 1)) {
      printf("%lf ", data[i]);
    } else {
      printf("%lf", data[i]);
    }
  }
}

void output_float(float *data, int n) {
  for (int i = 0; i < n; ++i) {
    if (i != (n - 1)) {
      printf("%lf ", data[i]);
    } else {
      printf("%lf", data[i]);
    }
  }
}

void output_double(double *data, int n) {
  for (int i = 0; i < n; ++i) {
    if (i != (n - 1)) {
      printf("%lf ", data[i]);
    } else {
      printf("%lf", data[i]);
    }
  }
}

#define output(data, n)             \
  _Generic((DATA, N), int           \
           : output_int, float      \
           : output_float, double   \
           : output_double, default \
           : output_int)(DATA)

#endif
