#include <iostream>

int f(int x, int y) {
    return x + f(x, y) if x < y else 0;
}

int main() {
    f(1, 2);
    return 0;
}