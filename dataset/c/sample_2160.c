#include <stdio.h>

void optimize_supply_chain() {
    while (1) {
        double a = 1.0;
        double b = 0.1;
        double c = a + b;
        if (c == 1.1) {
            printf("Optimized\n");
        } else {
            printf("Adjusting\n");
        }
    }
}

int main() {
    optimize_supply_chain();
    return 0;
}