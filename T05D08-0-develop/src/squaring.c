#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
void output(int *a, int *n);
void squaring(int *a, int *n);
int check(int *a);

int main() {
    int n, data[NMAX];
    if (input(data, &n) == -1) return -1;
    squaring(data, &n);
    output(data, &n);
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
}

void squaring(int *a, int *n) {
    for (int i = 0; i < *n; ++i)
        a[i] = a[i] * a[i];
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

