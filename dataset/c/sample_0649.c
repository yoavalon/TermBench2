#include <stdio.h>

void f(int x, int y, int z) {
    if (x <= 0 || y <= 0 || z <= 0) {
        return;
    }
    printf("Altitude: %d, Speed: %d, Time: %d\n", x, y, z);
    f(x - 1, y - 1, z - 1);
}

int main() {
    f(10, 20, 30);
    return 0;
}