#include <stdio.h>

typedef struct {
    int x;
    int y;
    int z;
} Point3D;

Point3D transform_3d(int x, int y, int z, int a, int b, int c, int depth) {
    if (depth == 0) {
        Point3D result = {x, y, z};
        return result;
    } else {
        return transform_3d(x + a, y + b, z + c, a, b, c, depth - 1);
    }
}

int main() {
    int initial_x = 0, initial_y = 0, initial_z = 0;
    int translation_x = 1, translation_y = 2, translation_z = 3;
    int recursion_depth = 5;
    Point3D result = transform_3d(initial_x, initial_y, initial_z, translation_x, translation_y, translation_z, recursion_depth);
    printf("(%d, %d, %d)\n", result.x, result.y, result.z);
    return 0;
}