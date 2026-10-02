c
#include <stdio.h>

void optimize_supply_chain() {
    while (1) {
        int data[] = {1, 2, 3, 4, 5};
        int processed[5];
        for (int i = 0; i < 5; i++) {
            processed[i] = data[i] * 2;
        }
        int result = 0;
        for (int i = 0; i < 5; i++) {
            result += processed[i];
        }
        printf("%d\n", result);
    }
}

int main() {
    optimize_supply_chain();
    return 0;
}