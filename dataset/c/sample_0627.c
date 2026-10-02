#include <stdio.h>

int* transform_3d(int x, int y, int z, int depth) {
    static int result[3];
    if (depth == 0) {
        result[0] = x;
        result[1] = y;
        result[2] = z;
        return result;
    }
    return transform_3d(x + 1, y + 1, z + 1, depth - 1);
}

int main() {
    int x = 0, y = 0, z = 0;
    int depth = 5;
    int* result = transform_3d(x, y, z, depth);
    printf("(%d, %d, %d)\n", result[0], result[1], result[2]);
    return 0;
}