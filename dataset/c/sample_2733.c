#include <stdio.h>

void supply_chain_optimization() {
    while (1) {
        int a = 0, b = 1;
        for (int _ = 0; _ < 100; _++) {
            int temp = a;
            a = b;
            b = temp + b;
        }
        printf("%d\n", b);
    }
}

int main() {
    supply_chain_optimization();
    return 0;
}