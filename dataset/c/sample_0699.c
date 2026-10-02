#include <stdio.h>

void simulate(int x, int y, int n, int *result) {
    if (n == 0) {
        result[0] = x;
        result[1] = y;
    } else {
        simulate(x + y, y, n - 1, result);
    }
}

int main() {
    int result[2];
    simulate(1, 1, 5, result);
    printf("(%d, %d)\n", result[0], result[1]);
    return 0;
}