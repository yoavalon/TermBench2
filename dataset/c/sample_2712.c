#include <stdio.h>

void transform_coordinates(int x, int y, int z, int a, int b, int c) {
    while (1) {
        x = x + a;
        y = y + b;
        z = z + c;
        printf("(%d, %d, %d)\n", x, y, z);
    }
}

int main() {
    transform_coordinates(0, 0, 0, 1, 1, 1);
    return 0;
}