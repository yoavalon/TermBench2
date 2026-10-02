#include <stdio.h>

int f(int x, int y) {
    return x < y ? x + f(x, y) : 0;
}

int main() {
    f(1, 2);
    return 0;
}