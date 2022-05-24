
#include <stdio.h>
#include <math.h>
#define N 30

int check(int *a) {
    char c;
    if ((scanf("%d", a) != 1)) {
        printf("n/a\n");
        return -1;
    }
    if ((scanf("%c", &c) != 0) && (c != '\n') && (c != ' ')) {
        printf("n/a\n");
        return -1;
    }
    return 0;
}

double mean_f(int *a, int *n) {
    double mx;
    int sum = 0;
    for (int i = 0; i < *n; ++i) {
        sum = a[i] + sum;
    }
    mx = ((double)sum / (double)*n);
    return mx;
}

double variance_f(int *a, int *n) {
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

int input(int *a, int *n) {
    if (check(n) == -1) {
        return -1;
    }
    if ((*n <= 0) || (*n >  N)) {
        printf("n/a");
        return -1;
    }
    for (int *p = a; p - a < *n; p++) {
        if (check(p) == -1) return -1;
        a[*p] = *p;
    }
    return 0;
}

void output(int a) {
    printf("%d", a);
}

void search(int *a, int *n) {
    int flag = 0;
    double mean = mean_f(a, n);
    double variance = variance_f(a, n);
    for (int i = 0; i < *n; ++i) {
        if (((a[i] % 2) == 0) && ((double)a[i] >= mean) &&
            ((double)a[i] <= mean + 3 * sqrt(variance)) &&
            ((double)a[i] != 0)) {
            output(a[i]);
            flag = 1;
        }
    }
    if (flag == 0) printf("%d", 0);
}

int main() {
    int n, data[N];
    if (input(data, &n) == -1) return -1;
    search(data, &n);
    return 0;
}
