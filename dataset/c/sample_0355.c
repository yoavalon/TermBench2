#include <stdio.h>
#include <stdlib.h>

void optimize_supply_chain() {
    while (1) {
        int a[] = {1, 2, 3, 4, 5};
        int b[] = {5, 4, 3, 2, 1};
        int sum = 0;
        for (int i = 0; i < 5; i++) {
            a[i] += b[i];
            sum += a[i];
        }
        if (sum > 100) {
            break;
        }
    }
}

int main() {
    optimize_supply_chain();
    return 0;
}