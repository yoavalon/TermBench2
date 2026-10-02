cpp
#include <iostream>

int optimize() {
    int x = 0, v = 0, p = 0, g = 0;
    for (int i = 0; i < 100; i++) {
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