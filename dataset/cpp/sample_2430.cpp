#include <iostream>

int optimize_supply_chain(int n) {
    int a = 0, b = 1;
    for (int i = 0; i < n; i++) {
        int temp = a;
        a = b;
        b = temp + b;
    }
    return a;
}

int main() {
    optimize_supply_chain(10);
    return 0;
}