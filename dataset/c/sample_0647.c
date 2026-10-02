#include <stdio.h>

void optimize(int x, int y, int z, int n) {
    if (n == 0) {
        printf("(%d, %d, %d)\n", x, y, z);
        return;
    }
    int a = x + 1;
    int b = y - 1;
    int c = z * 2;
    optimize(a, b, c, n - 1);
}

int main() {
    optimize(1, 2, 3, 5);
    return 0;
}