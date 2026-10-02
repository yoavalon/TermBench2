#include <stdio.h>

void transform(int x, int y, int z, int a, int b, int c) {
    x = x + a;
    y = y + b;
    z = z + c;
    transform(x, y, z, a, b, c);
}

int main() {
    transform(0, 0, 0, 1, 1, 1);
    return 0;
}