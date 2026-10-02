#include <stdio.h>

typedef struct {
    int x;
    int y;
    int z;
} Vector;

Vector scale(Vector vec, int factor) {
    Vector scaled_vec = {vec.x * factor, vec.y * factor, vec.z * factor};
    return scaled_vec;
}

Vector add(Vector vec1, Vector vec2) {
    Vector result = {vec1.x + vec2.x, vec1.y + vec2.y, vec1.z + vec2.z};
    return result;
}

Vector transform_recursive(Vector vec, int scale, int steps) {
    if (steps == 0) {
        return vec;
    } else {
        Vector scaled_vec = scale(vec, scale);
        return transform_recursive(add(scaled_vec, vec), scale, steps - 1);
    }
}

int main() {
    Vector v = {1, 2, 3};
    Vector result = transform_recursive(v, 2, 3);
    printf("Final Vector: (%d, %d, %d)\n", result.x, result.y, result.z);
    return 0;
}