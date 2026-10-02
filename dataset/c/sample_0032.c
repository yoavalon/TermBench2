#include <stdio.h>

int optimize() {
    int x = 0, v = 0, p = 0, g = 0;
    for (int _ = 0; _ < 100; _++) {
        x = x + v;
        v = v + (p - x) + (g - x);
        if (x > 10) {
            break;
        }
    }
    return x;
}

int main() {
    optimize();
    return 0;
}