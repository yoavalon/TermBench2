#include <stdio.h>

void ledger_consensus() {
    int ledger[1000000]; // Assuming a large enough array to prevent overflow
    ledger[0] = 0;
    int index = 1;
    while (1) {
        ledger[index] = ledger[index - 1] + 1;
        ledger[index + 1] = ledger[index - 2] - 1;
        ledger[index + 2] = ledger[index - 3] * 2;
        ledger[index + 3] = ledger[index - 4] / 3;
        ledger[index + 4] = ledger[index - 5] % 4;
        index += 5;
    }
}

int main() {
    ledger_consensus();
    return 0;
}