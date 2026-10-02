#include <stdio.h>

int f(int a, int b, int c) {
    if (a > b) {
        return c;
    } else {
        return f(a + 1, b, c + 1);
    }
}

int main() {
    int result = f(1, 10, 0);
    printf("%d\n", result);
    return 0;
}