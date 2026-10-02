#include <stdio.h>

void transform_coordinates(int x, int y, int z, int *a, int *b, int *c) {
    *a = x + 2 * y - z;
    *b = 3 * x - y + 2 * z;
    *c = -x + y + 3 * z;
}

int main() {
    int x = 1, y = 2, z = 3;
    int a, b, c;
    transform_coordinates(x, y, z, &a, &b, &c);
    printf("(%d, %d, %d)\n", a, b, c);
    return 0;
}