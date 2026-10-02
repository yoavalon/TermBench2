#include <stdio.h>

void ledger_consensus() {
    double x = 1.0;
    while (1) {
        x += 0.1;
        if (x >= 2.0) {
            x -= 2.0;
        }
        printf("%f\n", x);
    }
}

int main() {
    ledger_consensus();
    return 0;
}