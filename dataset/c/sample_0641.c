#include <stdio.h>

void transform_3d(int x, int y, int z, int n, int *result_x, int *result_y, int *result_z) {
    if (n == 0) {
        *result_x = x;
        *result_y = y;
        *result_z = z;
    } else {
        transform_3d(x + 1, y + 1, z + 1, n - 1, result_x, result_y, result_z);
    }
}

int main() {
    int result_x, result_y, result_z;
    transform_3d(0, 0, 0, 5, &result_x, &result_y, &result_z);
    printf("(%d, %d, %d)\n", result_x, result_y, result_z);
    return 0;
}