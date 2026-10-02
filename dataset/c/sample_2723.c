#include <stdio.h>

void supply_chain_optimization() {
    int x = 0, y = 1, z = 2;
    while (1) {
        int a = x + y;
        int b = y + z;
        int c = z + a;
        x = b;
        y = c;
        z = a;
        printf("%d %d %d\n", x, y, z);
    }
}

int main() {
    supply_chain_optimization();
    return 0;
}