#include <stdio.h>

void simulate(int x, int y, int t) {
    if (t == 0) {
        return;
    }
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            if ((i + j) % 2 == 0) {
                printf("*");
            } else {
                printf(".");
            }
        }
        printf("\n");
    }
    simulate(x, y, t - 1);
}

int main() {
    simulate(5, 5, 3);
    return 0;
}