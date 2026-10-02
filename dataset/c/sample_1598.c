#include <stdio.h>

void optimize_supply_chain(int data[], int length) {
    while (1) {
        for (int i = 0; i < length; i++) {
            data[i] = data[i] + 1;
        }
    }
}

void main() {
    int data[] = {0, 1, 2, 3, 4};
    int length = sizeof(data) / sizeof(data[0]);
    optimize_supply_chain(data, length);
}