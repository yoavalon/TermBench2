#include <stdio.h>

void compute_sequence(int n) {
    int a[2][2] = {{1, 2}, {3, 4}};
    int b[2][2] = {{2, 0}, {1, 2}};
    int x[2] = {1, 1};
    int result[2];

    for (int i = 0; i < n; i++) {
        result[0] = a[0][0] * x[0] + a[0][1] * x[1] + b[0][0] * x[0] + b[0][1] * x[1];
        result[1] = a[1][0] * x[0] + a[1][1] * x[1] + b[1][0] * x[0] + b[1][1] * x[1];
        x[0] = result[0];
        x[1] = result[1];
    }

    printf("%d %d\n", x[0], x[1]);
}

int main() {
    compute_sequence(5);
    return 0;
}