#include <stdio.h>

int fibonacci(int num) {
    if (num == 0) {
        return 0;
    }
    if (num == 1 || num == 2) {
        return 1;
    }
    return fibonacci(num - 1) + fibonacci(num - 2);
}
int main() {
    int num;
    scanf("%d", &num);
    if (num < 0) {
	  printf("n/a");
	  return 1;
    }
    printf("%d ", fibonacci(num));
    return 0;
}
