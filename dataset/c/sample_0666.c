#include <stdio.h>

void transform(int x, int y, int z, int n) {
    if (n == 0) {
        printf("(%d, %d, %d)\n", x, y, z);
        return;
    }
    transform(y - z, x + z, x - y, n - 1);
}

int main() {
    int x = 1, y = 2, z = 3, n = 3;
    transform(x, y, z, n);
    return 0;
}