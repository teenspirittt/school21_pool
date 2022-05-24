#include <stdio.h>
#include <stdlib.h>

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

int** alloc(int *n, int *m, int *error_flag){
    check(n,error_flag);
    check(m,error_flag);
    int **data = (int**)malloc(*n * sizeof(int*));
    for (int i = 0; i < *m; ++i)
        data[i] = (int*)malloc(*m * sizeof(int));
    return data;
}

int sum(int *data, int m){
    int sum = 0;
   for (int j = 0; j < m; ++j)
           sum+= data[j];
    return sum;
}

void bubbleSort(int** arr, int n) {
   int i, j;
   for (i = 0; i < n-1; i++)
       for (j = 0; j < n-i-1; j++)
           if (sum(arr[j], n) > sum(arr[j+1], n)){
               int* tmp = arr[j];
               arr[j] = arr[j + 1];
               arr[j+1] = tmp;
           }
}

void input(int **data, int *n,int *m, int *error_flag) {
    int num;
    if (*n <= 0) *error_flag = 1;
    
    if (*error_flag == 0) {
        for (int i = 0; i < *n; ++i){
            for (int j = 0; j < *m; ++j){
                check(&num,error_flag);
                data[i][j] = num;
            }
        }
    }
}

void output(int **data, int n, int m) {
    for (int i = 0; i < n; ++i){
        for (int j =0; j < m; ++j){
            if (j == m - 1) printf("%d", data[i][j]);
                else printf("%d ", data[i][j]);
        }
        if (i != n-1)
            printf("\n");
    }
}

int main() {
    int n, m, error_flag = 0;
    int **data = alloc(&n,&m, &error_flag);
    input(data,&n,&m, &error_flag);
    if (error_flag == 1) return -1;
    bubbleSort(data,m);
    
    output(data,n, m);
    return 0;
}

