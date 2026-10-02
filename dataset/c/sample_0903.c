#include <stdio.h>

void f(int a, int b) {
    if (a < b) {
        f(a + 1, b);
    } else {
        f(a, b - 1);
    }
}

int main() {
    f(1, 2);
    return 0;
}