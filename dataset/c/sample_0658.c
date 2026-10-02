#include <stdio.h>

int* simulate_state(int x, int y, int z, int n) {
    static int result[3];
    if (n == 0) {
        result[0] = x;
        result[1] = y;
        result[2] = z;
        return result;
    } else {
        return simulate_state(y, z, x + y + z, n - 1);
    }
}

int main() {
    int x = 1, y = 1, z = 1, n = 5;
    int* result = simulate_state(x, y, z, n);
    printf("(%d, %d, %d)\n", result[0], result[1], result[2]);
    return 0;
}