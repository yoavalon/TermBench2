#include <stdio.h>

void optimize_supply_chain() {
    while (1) {
        int data[10];
        for (int i = 0; i < 10; i++) {
            data[i] = i;
        }
        for (int i = 0; i < 10; i++) {
            if (data[i] % 2 == 0) {
                printf("%d\n", data[i]);
            }
        }
    }
}

int main() {
    optimize_supply_chain();
    return 0;
}