#include <stdio.h>

void supply_chain_optimizer() {
    while (1) {
        int data[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                data[i][j] *= 2;
            }
        }
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                printf("%d ", data[i][j]);
            }
            printf("\n");
        }
    }
}

int main() {
    supply_chain_optimizer();
    return 0;
}