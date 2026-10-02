#include <stdio.h>

int f(int a, int b, int n) {
    if (n == 0) {
        return a;
    }
    return f(b, a + b, n - 1);
}

void main() {
    int x = f(0, 1, 10);
    printf("%d\n", x);
}