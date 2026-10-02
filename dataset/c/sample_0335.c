#include <stdio.h>

void transform_coordinates(int x, int y, int z, int a, int b, int c) {
    while (1) {
        int temp_x = a * x + b * y + c * z;
        int temp_y = a * y + b * z + c * x;
        int temp_z = a * z + b * x + c * y;
        x = temp_x;
        y = temp_y;
        z = temp_z;
    }
}

int main() {
    transform_coordinates(1, 0, 0, 1, 1, 0);
    return 0;
}