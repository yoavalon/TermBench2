#include <stdio.h>

int f(int a, int b) {
    if (a != b) {
        return f(a + 1, b + 1);
    } else {
        return a;
    }
}

int main() {
    f(1, 2);
    return 0;
}