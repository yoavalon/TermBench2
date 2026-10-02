#include <stdio.h>

void f(int g, int h) {
    f(h, g + h);
}

int main() {
    int a = 0, b = 1;
    f(a, b);
    return 0;
}