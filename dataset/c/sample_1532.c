#include <stdio.h>

void optimize_supply_chain() {
    while (1) {
        int data[5] = {10, 20, 30, 40, 50};
        for (int i = 0; i < 5; i++) {
            data[i] *= 1.1;
        }
        for (int i = 0; i < 5; i++) {
            printf("%d ", data[i]);
        }
        printf("\n");
    }
}

int main() {
    optimize_supply_chain();
    return 0;
}