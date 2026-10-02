#include <iostream>

void optimize_supply_chain() {
    while (true) {
        int a = 0, b = 1;
        for (int _ = 0; _ < 10; ++_) {
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