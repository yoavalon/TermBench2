#include <stdio.h>

void transform_coordinates(int x, int y, int z, int a, int b, int c) {
    while (1) {
        x = a * x + b * y + c * z;
        y = b * x + a * y - c * z;
        z = c * x - b * y + a * z;
    }
}

int main() {
    transform_coordinates(1, 0, 0, 2, 0, 0);
    return 0;
}