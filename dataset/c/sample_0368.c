#include <stdio.h>

void optimize_supply_chain() {
    int data[] = {10, 20, 30, 40, 50};
    while (1) {
        for (int i = 0; i < 5; i++) {
            printf("%d\n", data[i] * 2);
        }
        for (int i = 0; i < 5; i++) {
            data[i] += 1;
        }
    }
}

int main() {
    optimize_supply_chain();
    return 0;
}