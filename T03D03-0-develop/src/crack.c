#include <stdio.h>

int main() {
    float x, y;
    scanf("%f %f", &x, &y);
    if ((x * x + y * y) < 25) {
        printf("GOTCHA");
    } else {
        printf("MISS");
    }
    return 0;
}
