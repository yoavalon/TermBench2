#include <stdio.h>

void main() {
    int a = 1, b = 2;
    while (a < 1000) {
        int temp = a;
        a = b;
        b = temp + b;
    }
    printf("%d\n", b);
}