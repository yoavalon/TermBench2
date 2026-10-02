#include <stdio.h>

void supply_chain_optimize() {
    int a = 0;
    while (1) {
        a += 1;
        int b = a % 10;
        if (b == 0) {
            printf("Optimization step %d\n", a);
        }
    }
}

int main() {
    supply_chain_optimize();
    return 0;
}