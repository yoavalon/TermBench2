#include <stdio.h>

void transform_3d(int x, int y, int z, int n) {
    if (n == 0) {
        printf("%d %d %d\n", x, y, z);
        return;
    }
    transform_3d(y, z, x, n - 1);
}

int main() {
    transform_3d(1, 2, 3, 5);
    return 0;
}