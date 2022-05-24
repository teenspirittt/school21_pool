#include <stdio.h>

void arith(int a, int b) {
    printf("%d\t", a+b);
    printf("%d\t", a-b);
    printf("%d\t", a*b);

    if (b != 0) {
        printf("%d\t\n", a/b);
    } else {
        printf("n/a\t\n");
    }
}

void check() {
char c;
float num_1, num_2;
    if (scanf("%f %f", &num_1, &num_2) != 2) {
        printf("n/a\n");
        return;
        }
    if (!((num_1 == (int)num_1) && (num_2 == (int)num_2))) {
        printf("n/a\n");
        return;
    }
    if ((scanf("%c", &c) !=0) && (c != '\n')) {
        printf("n/a\n");
        return;
    }
    arith(num_1, num_2);
}

int main() {
    check();
    return 0;
}



