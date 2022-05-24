#include <stdio.h>
#include <stdlib.h>
#define N 10

void swap(int *le, int *ne) {
    int tmp;
    tmp = *le;
    *le = *ne;
    *ne = tmp;
}

void bubble_sort(int *list, int n) {
    int t;
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (list[j] > list[j + 1])
                swap(&list[j], &list[j + 1]);

}

void check(int *num, int *error_flag) {
    char c;
    if ((scanf("%d", num) != 1)) {
        printf("n/a");
        *error_flag = 1;
    }
    if ((scanf("%c", &c) != 0) && (c != '\n') && (c != ' ')) {
        printf("n/a");
        *error_flag = 1;
    }
}

void input(int **data, int *n, int *error_flag) {
    check(n,error_flag);
    if (*n <= 0) *error_flag = 1;
    *data = (int*)malloc(*n * sizeof(int));
    for (int *p = *data; p - *data < *n; p++){
        check(p,error_flag);

    }
}

void output(int *data, int n) {
    for (int i = 0; i < n; ++i)
        printf("%d ", data[i]);
}

int main() {
    int n, error_flag = 0;
    int *data;
    input(&data,&n, &error_flag);
    if (error_flag == 1) return -1;
    bubble_sort(data,n);
    output(data,n);
    free(data);
    return 0;
}


