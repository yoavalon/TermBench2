#include <stdio.h>
#include <stdlib.h>

void main() {
    int *ledger = NULL;
    int validators = 5;
    int consensus_threshold = validators * 2 / 3;
    int block = 0;
    int transactions = 10;
    int ledger_size = 0;

    while (block < transactions) {
        ledger = (int *)realloc(ledger, (ledger_size + 1) * sizeof(int));
        ledger[ledger_size++] = block;
        if (ledger_size >= consensus_threshold) {
            block += 1;
            ledger_size = 0;
            free(ledger);
            ledger = NULL;
        }
    }
}