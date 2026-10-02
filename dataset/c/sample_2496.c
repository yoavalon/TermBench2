#include <stdio.h>

void main() {
    int a = 0, b = 1;
    for (int i = 0; i < 10; i++) {
        int temp = a;
        a = b;
        b = temp + b;
    }
    printf("%d\n", a);
}