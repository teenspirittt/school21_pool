#include <stdio.h>

#define N 10

void swap(int *le, int *ne) {
    int tmp;
    tmp = *le;
    *le = *ne;
    *ne = tmp;
}

void merge(int *arr, int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

void quick_sort(int *data, int first, int last) {
    if (first < last) {
        int left = first, right = last, middle = data[(left + right) / 2];
        do {
            while (data[left] < middle) left++;
            while (data[right] > middle) right--;
            if (left <= right) {
                int tmp = data[left];
                data[left] = data[right];
                data[right] = tmp;
                left++;
                right--;
            }
        } while (left <= right);
        quick_sort(data, first, right);
        quick_sort(data, left, last);
    }
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
    printf("\n");
}

int main() {
    int data[N];
    if (input(data) == -1) return -1;
    quick_sort(data, 0, N - 1);
    output(data);
    mergeSort(data, 0, N - 1);
    output(data);
    return 0;
}
