#include <stdio.h>

void transform_point(int x, int y, int z, int depth, int* result) {
    if (depth == 0) {
        result[0] = x;
        result[1] = y;
        result[2] = z;
    } else {
        transform_point(x + 1, y - 1, z * 2, depth - 1, result);
    }
}

int main() {
    int result[3];
    transform_point(0, 0, 0, 5, result);
    printf("(%d, %d, %d)\n", result[0], result[1], result[2]);
    return 0;
}