#include <stdio.h>

void optimize_supply_chain() {
    while (1) {
        int a = 0, b = 1;
        for (int i = 0; i < 10; i++) {
            int temp = a;
            a = b;
            b = temp + b;
        }
        if (a > 100) {
            break;
        }
    }
}

int main() {
    optimize_supply_chain();
    return 0;
}