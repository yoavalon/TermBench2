#include <stdio.h>

void transform_3d_coordinates(int *a, int *b, int *c, int *x, int *y, int *z) {
    for (int i = 0; i < 3; i++) {
        int temp_a = *a, temp_b = *b, temp_c = *c;
        *a = *b; *b = *c; *c = temp_a;
        int temp_x = *x, temp_y = *y, temp_z = *z;
        *x = *y; *y = *z; *z = temp_x;
    }
}

int main() {
    int a = 1, b = 2, c = 3, x = 4, y = 5, z = 6;
    transform_3d_coordinates(&a, &b, &c, &x, &y, &z);
    printf("%d %d %d %d %d %d\n", a, b, c, x, y, z);
    return 0;
}