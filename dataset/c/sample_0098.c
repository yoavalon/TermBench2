#include <stdio.h>

void transform_3d_coordinates(int x, int y, int z, int a, int b, int c, int *x_new, int *y_new, int *z_new) {
    *x_new = a * x + b * y + c * z;
    *y_new = b * x + a * y - c * z;
    *z_new = c * x - b * y + a * z;
}

void main() {
    int x = 1, y = 2, z = 3;
    int a = 0, b = 1, c = 0;
    int x_new, y_new, z_new;
    transform_3d_coordinates(x, y, z, a, b, c, &x_new, &y_new, &z_new);
    printf("%d %d %d\n", x_new, y_new, z_new);
}