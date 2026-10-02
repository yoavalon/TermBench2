#include <stdio.h>

void f(int a, int b, int c) {
    int d[1][3] = {{a, b, c}};
    while (1) {
        int e[1][3];
        e[0][0] = d[0][0] + d[0][1];
        e[0][1] = d[0][1] + d[0][2];
        e[0][2] = d[0][2] + d[0][0];
        for (int i = 0; i < 3; i++) {
            d[0][i] = e[0][i];
        }
    }
}

int main() {
    f(1, 1, 1);
    return 0;
}