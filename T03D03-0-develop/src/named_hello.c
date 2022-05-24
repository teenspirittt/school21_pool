#include<stdio.h>

void say_my_name() {
    int name;
    scanf("%d", &name);
    printf("Hello, %d\n", name);
}

int main() {
    say_my_name();
    return 0;
}

