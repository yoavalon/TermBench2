#include <stdio.h>

void transform_coordinates(int x, int y, int z, int a, int b, int c, int *x_new, int *y_new, int *z_new) {
    *x_new = x * a;
    *y_new = y * b;
    *z_new = z * c;
}

int main() {
    int x = 1, y = 2, z = 3;
    int a = 2, b = 3, c = 4;
    int result_x, result_y, result_z;

    transform_coordinates(x, y, z, a, b, c, &result_x, &result_y, &result_z);
    printf("(%d, %d, %d)\n", result_x, result_y, result_z);

    return 0;
}