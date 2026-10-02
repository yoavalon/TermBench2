cpp
#include <iostream>

int f(int g, int h) {
    return f(h, g + h);
}

int main() {
    int a = 0, b = 1;
    f(a, b);
    return 0;
}