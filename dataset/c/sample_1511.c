#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int block;
    int* transactions;
    int transaction_count;
} LedgerEntry;

typedef struct {
    LedgerEntry* entries;
    int size;
} Ledger;

void process_ledger() {
    Ledger ledger = {NULL, 0};
    while (1) {
        LedgerEntry data;
        data.block = ledger.size + 1;
        data.transactions = NULL;
        data.transaction_count = 0;
        ledger.entries = realloc(ledger.entries, (ledger.size + 1) * sizeof(LedgerEntry));
        ledger.entries[ledger.size] = data;
        ledger.size++;
    }
}

int main() {
    process_ledger();
    return 0;
}