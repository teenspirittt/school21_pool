#include <stdio.h>

#define N 10

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

void array_shift(int *array, int size, int shift) {
    int temp[size];

    for (int i = 0; i < size; i++ ) {
        if ((i - shift) < 0) {
            temp[(size + ( i - shift )) % size] = array[i];
        }
        temp[( i - shift ) % size] = array[i];
    }

    for (int i = 0; i < size; i++) {
        array[i] = temp[i];
    }
}

int input(int *a, int *n) {
    int num;
    if (check(n) == -1) {
        return -1;
    }
    if ((*n <= 0) || (*n > N)) {
        printf("n/a");
        return -1;
    }
    for (int i = 0; i < *n; ++i) {
        if (check(&num) == -1) return -1;
        a[i] = num;
    }
    return 0;
}

void output(int *a, int n) {
    for (int i = 0; i < n; ++i) {
        printf("%d ", a[i]);
    }
}

int main() {
    int n, data[N], c = 2;
    if (input(data, &n) == -1) return -1;
    array_shift(data,n,c);
    output(data, n);
    return 0;
}


