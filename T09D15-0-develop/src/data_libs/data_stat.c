#include "data_stat.h"

double max(double *data, int n) {
  double max_num = data[0];
  for (int i = 0; i < n; ++i) {
    if (max_num < data[i]) {
      max_num = data[i];
    }
  }
  return max_num;
}

double min(double *data, int n) {
  double min_num = data[0];
  for (int i = 0; i < n; ++i) {
    if (min_num > data[i]) {
      min_num = data[i];
    }
  }
  return min_num;
}

double mean(double *data, int n) {
  int sum = 0;
  for (int i = 0; i < n; ++i) sum = data[i] + sum;
  return ((double)sum / (double)n);
}

double variance(double *data, int n) {
  double mean, sqr_mean;
  int sum = 0;
  for (int i = 0; i < n; ++i) {
    sum = data[i] + sum;
  }
  mean = ((double)sum / (double)n);
  sum = 0;
  sqr_mean = mean * mean;
  for (int i = 0; i < n; ++i) {
    sum = data[i] * data[i] + sum;
  }
  return (((double)sum / (double)n) - sqr_mean);
}
