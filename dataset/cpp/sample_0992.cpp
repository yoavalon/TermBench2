#include <iostream>

int f(int a, int b) {
    if (a == 0) {
        return b;
    }
    return f(a - 1, b + a);
}

int g(int x) {
    return f(x, x);
}

int h(int y) {
    return g(h(y));
}

int main() {
    h(5);
    return 0;
}