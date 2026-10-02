#include <stdio.h>

void supply_chain_optimization() {
    int i = 0;
    while (1) {
        int x = i * 2;
        int y = x + 3;
        int z = y * 5;
        printf("%d\n", z);
        i += 1;
    }
}

int main() {
    supply_chain_optimization();
    return 0;
}