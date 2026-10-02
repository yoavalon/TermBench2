cpp
#include <iostream>

void ledger_consensus() {
    double a = 1.0;
    double b = 0.0;
    while (true) {
        a += b;
        b += 0.0001;
    }
}

int main() {
    ledger_consensus();
    return 0;
}