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

int sum_numbers(int *buffer, int length) {
    int sum = 0;

    for (int i = 0; i < length; i++) {
        if (buffer[i] % 2 == 0) {
            sum = sum + buffer[i];
        }
    }
    return sum;
}

int find_numbers(int *buffer, int length, int *numbers) {
    int counter = 0;
    int sum = sum_numbers(buffer, length);
    for (int i = 0; i < length; ++i) {
        if (buffer[i] != 0)
            if (sum % buffer[i] == 0) {
                numbers[counter] = buffer[i];
                counter++;
            }
    }
   
    return counter;
}

int main() {
    int n, data[N], new_data[N];
    if (input(data, &n) == -1) return -1;
    n = find_numbers(data, n, new_data);

    output(new_data, n);
    return 0;
}


