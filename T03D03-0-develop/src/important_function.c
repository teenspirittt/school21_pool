#include <stdio.h>
#include <math.h>


int main() {
    double x;
    scanf("%lf", &x);

    double y = 7e-3 * pow(x, 4) + ((22.8 * pow(x, 1 / 3) - 1e3) * x + 3) /
    (x * x / 2) - x * pow((10 + x), (2 / x)) - 1.01;

    printf("%.1f", round(y*10)/10);
    return 0;
}

