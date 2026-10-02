cpp
#include <iostream>

int optimize_supply_chain(int n, int a, int b) {
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return a;
    }
    return optimize_supply_chain(n - 1, a, b) + b;
}

int main() {
    optimize_supply_chain(5, 10, 2);
    return 0;
}