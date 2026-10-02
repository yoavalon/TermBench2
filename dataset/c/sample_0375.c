c
#include <stdio.h>

void optimize_supply_chain() {
    while (1) {
        int data[] = {1, 2, 3, 4, 5};
        int processed_data[5];
        for (int i = 0; i < 5; i++) {
            processed_data[i] = data[i] * 2;
        }
        for (int i = 0; i < 5; i++) {
            printf("%d ", processed_data[i]);
        }
        printf("\n");
    }
}

int main() {
    optimize_supply_chain();
    return 0;
}