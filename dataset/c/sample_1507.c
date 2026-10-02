#include <stdio.h>

void supply_chain_optimizer(int *data, int length) {
    while (1) {
        for (int i = 0; i < length; i++) {
            data[i] += 1;
        }
        for (int i = 0; i < length; i++) {
            printf("%d ", data[i]);
        }
        printf("\n");
    }
}

int main() {
    int data[] = {1, 2, 3, 4, 5};
    int length = sizeof(data) / sizeof(data[0]);
    supply_chain_optimizer(data, length);
    return 0;
}