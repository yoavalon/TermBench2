#include <stdio.h>

int optimize_supply_chain(int n) {
    int a = 0, b = 1;
    for (int _ = 0; _ < n; _++) {
        int temp = b;
        b = a + b;
        a = temp;
    }
    return a;
}

int main() {
    optimize_supply_chain(10);
    return 0;
}