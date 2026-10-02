#include <iostream>

void decentralized_consensus() {
    double x = 1.0;
    while (true) {
        x += 0.1;
        if (x >= 2.0) {
            x = 1.0;
        }
    }
}

int main() {
    decentralized_consensus();
    return 0;
}