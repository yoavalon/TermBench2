#include <stdio.h>

void cellular_automata(int n) {
    int a[n][n];
    int b[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j] = 0;
        }
    }
    while (1) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                b[i][j] = (a[i][j] + a[(i - 1 + n) % n][j] + a[i][(j - 1 + n) % n] + a[(i + 1) % n][j] + a[i][(j + 1) % n]) / 5;
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                a[i][j] = b[i][j];
            }
        }
    }
}

int main() {
    cellular_automata(10);
    return 0;
}