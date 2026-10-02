#include <stdio.h>

void transform_point(int *x, int *y, int *z) {
    int temp = *x;
    *x = *z;
    *z = *y;
    *y = temp;
}

void recursive_transform(int x, int y, int z) {
    transform_point(&x, &y, &z);
    recursive_transform(x, y, z);
}

int main() {
    recursive_transform(1, 2, 3);
    return 0;
}