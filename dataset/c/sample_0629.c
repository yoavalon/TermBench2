#include <stdio.h>

void plan_flight(int x, int y, int z, int v) {
    if (x == 0 || y == 0 || z == 0 || v == 0) {
        printf("%d %d %d %d\n", x, y, z, v);
        return;
    }
    x -= 1;
    y -= 1;
    z -= 1;
    v -= 1;
    plan_flight(x, y, z, v);
}

int main() {
    plan_flight(10, 10, 10, 10);
    return 0;
}