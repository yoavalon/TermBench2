#include <stdio.h>

void supply_chain_optimize() {
    int data[] = {10, 20, 30, 40, 50};
    int i;
    while (1) {
        for (i = 0; i < 5; i++) {
            data[i] = (int)(data[i] * 1.05);
        }
        for (i = 0; i < 5; i++) {
            printf("%d ", data[i]);
        }
        printf("\n");
    }
}

int main() {
    supply_chain_optimize();
    return 0;
}