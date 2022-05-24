#include <stdio.h>

#define N 10

void swap(int *le, int *ne) {
    int tmp;
    tmp = *le;
    *le = *ne;
    *ne = tmp;
}

void bubble_sort(int *list) {
    int t;
    for (int i = 0; i < N - 1; i++)
        for (int j = 0; j < N - i - 1; j++)
            if (list[j] > list[j + 1])
                swap(&list[j], &list[j + 1]);

}

int check(int *num) {
    char c;
    if ((scanf("%d", num) != 1)) {
        printf("n/a\n");
        return -1;
    }
    if ((scanf("%c", &c) != 0) && (c != '\n') && (c != ' ')) {
        printf("n/a\n");
        return -1;
    }
    return 0;
}

int input(int *data) {

    for (int *p = data; p - data < N - 1; p++) {
        if (check(p) == -1) return -1;
        data[*p] = *p;
    }
    return 0;
}

void output(int *data) {
    for (int i = 0; i < N; ++i)
        printf("%d ", data[i]);
}

int main() {
    int data[N];
    if (input(data) == -1) return -1;
    bubble_sort(data);
    output(data);
    return 0;
}
