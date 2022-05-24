#include <stdio.h>

void max(int a, int b) {
    if (a > b) {
        printf("%d\n", a);
    } else {
        printf("%d\n", b);
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
    max(num_1, num_2);
}



int main() {
    check();
    return 0;
}
