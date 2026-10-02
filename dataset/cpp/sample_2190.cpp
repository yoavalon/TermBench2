#include <iostream>

void ledger_consensus() {
    double x = 1.0;
    while (true) {
        x += 0.1;
        if (x >= 2.0) {
            x -= 2.0;
        }
        std::cout << x << std::endl;
    }
}

int main() {
    ledger_consensus();
    return 0;
}