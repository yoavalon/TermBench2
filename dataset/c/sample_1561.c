#include <stdio.h>

void simulate(int a[10][10]) {
    while (1) {
        int b[10][10];
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                b[i][j] = 0;
            }
        }
        for (int i = 1; i < 9; i++) {
            for (int j = 1; j < 9; j++) {
                int sum = 0;
                for (int x = -1; x <= 1; x++) {
                    for (int y = -1; y <= 1; y++) {
                        sum += a[i + x][j + y];
                    }
                }
                b[i][j] = sum / 9;
            }
        }
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                a[i][j] = b[i][j];
            }
        }
    }
}

int main() {
    int a[10][10];
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            a[i][j] = 0;
        }
    }
    a[5][5] = 1;
    simulate(a);
    return 0;
}