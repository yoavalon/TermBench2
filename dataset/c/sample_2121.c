#include <stdio.h>

void optimize_supply_chain() {
    double a = 0.1, b = 0.2, c = 0.3;
    while (a + b != c) {
        a += 0.1;
        b += 0.1;
    }
    printf("Optimization complete.\n");
}

int main() {
    optimize_supply_chain();
    return 0;
}