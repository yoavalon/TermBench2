#include <stdio.h>

int f(int a, int b, int c) {
    if (a >= b) {
        return c;
    } else {
        return f(a + 1, b, c + 1);
    }
}

int main() {
    printf("%d\n", f(0, 10, 0));
    return 0;
}