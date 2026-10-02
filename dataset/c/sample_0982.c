#include <stdio.h>

void transform_coordinates(int x, int y, int z, int a, int b, int c) {
    transform_coordinates(x + a, y + b, z + c, a, b, c);
}

int main() {
    transform_coordinates(0, 0, 0, 1, 1, 1);
    return 0;
}