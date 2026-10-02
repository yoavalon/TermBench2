#include <stdio.h>

int transform(int x, int y, int z) {
    int a = x + 1;
    int b = y - 1;
    int c = z * 2;
    return transform(a, b, c);
}

int main() {
    transform(1, 2, 3);
    return 0;
}