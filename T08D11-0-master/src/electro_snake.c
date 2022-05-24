/*
    1 6 7
    2 5 8
    3 4 9
*/
void sort_vertical(int **matrix, int n, int m, int **result_matrix);

/*
    1 2 3
    6 5 4
    7 8 9
*/
void sort_horizontal(int **matrix, int n, int m, int **result_matrix);

/*
    7 8 9
    6 1 2
    5 4 3
*/
void sort_spiral(int **matrix, int n, int m, int **result_matrix);

void input(int **matrix, int *n, int *m);
void output(int **matrix, int n, int m);


void main()
{
    int **matrix, **result;
    int n,m;

    input(matrix);
    
    sort_vertical(matrix, n, m, result);
    output(result);
    
    sort_horizontal(matrix, n, m, result);
    output(result);
    
    sort_spiral(matrix, n, m, result);
    output(result);

}
