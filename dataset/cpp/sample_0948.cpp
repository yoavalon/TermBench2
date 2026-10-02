cpp
#include <iostream>

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
    while (true) {
        std::cout << f(a, b) << std::endl;
    }
    return 0;
}