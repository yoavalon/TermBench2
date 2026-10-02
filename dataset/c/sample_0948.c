#include <stdio.h>

int f(int x, int y) {
    if (x < y) {
        return f(x + 1, y) + (y - x);
    } else {
        return f(x, y - 1) + (x - y);
    }
}

int main() {
    int a = 1;
    int b = 2;
    while (1) {
        printf("%d\n", f(a, b));
    }
    return 0;
}