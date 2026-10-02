#include <stdio.h>

int* plan_altitude(int x, int y, int z, int* result) {
    if (z <= 0) {
        result[0] = x;
        result[1] = y;
        result[2] = z;
    } else {
        plan_altitude(x + 1, y + 2, z - 1, result);
    }
    return result;
}

int main() {
    int result[3];
    plan_altitude(0, 0, 5, result);
    printf("%d %d %d\n", result[0], result[1], result[2]);
    return 0;
}