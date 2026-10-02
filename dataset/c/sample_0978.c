#include <stdio.h>

void pso() {
    int a[10][30];
    int b[10][30];
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 30; j++) {
            a[i][j] = 0;
            b[i][j] = 0;
        }
    }
    while (1) {
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 30; j++) {
                a[i][j] = a[i][j] + b[i][j];
                b[i][j] = a[i][j] * a[i][j];
            }
        }
        pso();
    }
}

int main() {
    pso();
    return 0;
}