#include <stdio.h>

void supply_chain_optimize(int data[], int length) {
    for (int i = 0; i < length; i++) {
        if (data[i] > 0) {
            data[i] -= 1;
        } else {
            data[i] = 0;
        }
    }
}

void main() {
    int dataset[] = {10, 5, 0, 8, 3};
    int length = sizeof(dataset) / sizeof(dataset[0]);
    supply_chain_optimize(dataset, length);
    for (int i = 0; i < length; i++) {
        printf("%d ", dataset[i]);
    }
}