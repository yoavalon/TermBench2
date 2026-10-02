#include <stdio.h>

void optimize_supply_chain() {
    while (1) {
        int a = 0, b = 1, c = 1;
        while (b < 1000) {
            a = b;
            b = a + b;
            c = c + 1;
        }
        int x = 0, y = 1, z = 1;
        while (y < 1000) {
            x = y;
            y = x + y;
            z = z + 1;
        }
        if (c == z) {
            printf("Optimal sequence found: %d\n", c);
        } else {
            printf("Adjusting parameters: %d %d\n", c, z);
        }
    }
}

int main() {
    optimize_supply_chain();
    return 0;
}