#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
void output(int *a, int *n);
int max(int *a, int *n);
int min(int *a, int *n);
double mean(int *a, int *n);
double variance(int *a, int *n);
int check(int *a);
void output_result(int max_v,
                   int min_v,
                   double mean_v,
                   double variance_v);

int main() {
    int n, data[NMAX];
    if (input(data, &n) == -1) return -1;
    output(data, &n);
    output_result(max(data, &n),
                  min(data, &n),
                  mean(data, &n),
                  variance(data, &n));
    return 0;
}
int input(int *a, int *n) {
    if (check(n) == -1) {
        return -1;
    }
    if ((*n <= 0) || (*n > 10)) {
        printf("n/a");
        return -1;
    }
    for (int *p = a; p - a < *n; p++) {
        if (check(p) == -1) return -1;
        a[*p] = *p;
    }
    return 0;
}


void output(int *a, int *n) {
    for (int i = 0; i < *n; ++i)
        printf("%d ", a[i]);
    printf("\n");
}

void output_result(int max_v, int min_v,
                   double mean_v, double variance_v) {
    printf("%d %d %.6f %.6f", max_v, min_v, mean_v, variance_v);
}

int max(int *a, int *n) {
    int max_num = a[0];
    for (int i = 0; i < *n; i++)
        if (max_num < a[i])
            max_num = a[i];
    return max_num;
}

int min(int *a, int *n) {
    int min_num = a[0];
    for (int i = 0; i < *n; i++)
        if (min_num > a[i])
            min_num = a[i];
    return min_num;
}
double mean(int *a, int *n) {
    double mx;
    int sum = 0;
    for (int i = 0; i < *n; ++i) {
        sum = a[i] + sum;
    }
    mx = ((double)sum / (double)*n);
    return mx;
}

double variance(int *a, int *n) {
    double xi2pi = 0;
    double mean, sqr_mean;
    double dx = 0;
    int sum = 0;
    for (int i = 0; i < *n; ++i) {
        sum = a[i] + sum;
    }
    mean = ((double)sum / (double)*n);
    sum = 0;
    sqr_mean = mean * mean;
    for (int i = 0; i < *n; ++i) {
        sum = a[i] * a[i] + sum;
    }
    xi2pi = (double)sum / (double)*n;
    dx = xi2pi - sqr_mean;
    return dx;
}

int check(int *a) {
    char c;
    if ((scanf("%d", a) != 1)) {
        printf("n/a\n");
        return -1;
    }
    if ((scanf("%c", &c) !=0) && (c != '\n') && (c != ' ')) {
        printf("n/a\n");
        return -1;
    }
    return 0;
}
