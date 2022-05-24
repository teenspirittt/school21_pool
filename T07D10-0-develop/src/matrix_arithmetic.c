#include <stdio.h>
#include <stdlib.h>

void input(int ***matrix, int n, int m,int *error_flag);
void output(int **matrix, int n, int m);
void sum(int **a_matrix, int **b_matrix, int **r_matrix,int n, int m);
void transpose(int **matrix, int **r_matrix, int n, int m);
void mul(int **a_matrix, int **b_matrix, int **r_matrix, int row1, int col1, int row2, int col2);
void check(int *num, int *error_flag);
void alloc(int ***data, int *n, int *m, int *error_flag, int flag);


int main() {
    int choise;
    int row1, col1, row2, col2, error_flag = 0;
    int **a_matrix;
    int **b_matrix;
    int **r_matrix;
    
    
    
    scanf("%d", &choise);
    switch(choise) {
        case 1:
            alloc(&a_matrix,&row1,&col1, &error_flag, 0);
            input(&a_matrix,row1,col1, &error_flag);
            if (error_flag == 1) return -1;
            
            alloc(&b_matrix,&row2,&col2, &error_flag, 0);
            if (col1 != row2) {
                printf("n/a");
                return -1;
            }
            input(&b_matrix,row2,col2, &error_flag);
            if (error_flag == 1) return -1;
            alloc(&r_matrix,&row1,&col1, &error_flag, 1);
            sum(a_matrix, b_matrix, r_matrix,row1,col1);
            output(r_matrix, row1, col1);
            break;
        case 2:
            alloc(&a_matrix,&row1,&col1, &error_flag, 0);
            input(&a_matrix,row1,col1, &error_flag);
            if (error_flag == 1) return -1;
            
            alloc(&b_matrix,&row2,&col2, &error_flag, 0);
            if (col1 != row2) {
                printf("n/a");
                return -1;
            }
            input(&b_matrix,row2,col2, &error_flag);
            if (error_flag == 1) return -1;
            alloc(&r_matrix,&row1,&col1, &error_flag, 1);
            mul(a_matrix, b_matrix, r_matrix,row1,col1,row2,col2);
            output(r_matrix, row1, col1);
            break;
        case 3:
            alloc(&a_matrix,&row1,&col1, &error_flag, 0);
            input(&a_matrix,row1,col1, &error_flag);
            if (error_flag == 1) return -1;
            
            alloc(&b_matrix,&row2,&col2, &error_flag, 0);
            if (col1 != row2) {
                printf("n/a");
                return -1;
            }
            input(&b_matrix,row2,col2, &error_flag);
            if (error_flag == 1) return -1;
            alloc(&r_matrix,&col1,&row1, &error_flag, 1);
            transpose(a_matrix, r_matrix,row1, col1);
            output(r_matrix, col1, row1);
            break;
            
        default:
            printf("n/a");
            break;
    
    }

    return 0;
}

void transpose(int **matrix, int **r_matrix, int row1, int col1){
    
    for (int i = 0; i < row1; ++i)
        for (int j = 0; j < col1; ++j)
            r_matrix[j][i] = matrix[i][j];
    
}

void sum(int **a_matrix, int **b_matrix, int **r_matrix,int n, int m){
    for(int i =0; i < n; ++i){
        for (int j =0; j < m; ++j) {
            r_matrix[i][j] = a_matrix[i][j] + b_matrix[i][j];
        }
    }
}

void mul(int **a_matrix, int **b_matrix, int **r_matrix, int row1, int col1, int row2, int col2){
    for (int i =  0; i < row1; ++i)
        for (int j = 0; j < col2; ++j){
            r_matrix[i][j] = 0;
            for(int k = 0; k < col1; ++k)
                r_matrix[i][j]+= a_matrix[i][k] * b_matrix[k][j];
        }
}

void alloc(int ***data, int *n, int *m, int *error_flag, int flag){
    if (flag == 0) {
    check(n,error_flag);
    check(m,error_flag);
    }
    *data = (int**)malloc(*n * sizeof(int*));
    for (int i = 0; i < *m; ++i)
        (*data)[i] = (int*)malloc(*m * sizeof(int));
    
}

void input(int ***matrix, int n,int m, int *error_flag) {
    int num;
    if (n <= 0) *error_flag = 1;
    
    if (*error_flag == 0) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                check(&num,error_flag);
                (*matrix)[i][j] = num;
            }
        }
    }
}

void output(int **matrix, int n, int m) {
    for (int i = 0; i < n; ++i) {
        for (int j =0; j < m; ++j) {
            if (j == m - 1) printf("%d", matrix[i][j]);
                else printf("%d ", matrix[i][j]);
        }
        if (i != n-1)
            printf("\n");
    }
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
