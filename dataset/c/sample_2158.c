#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    double balance;
    double pending;
} Account;

typedef struct {
    char *key;
    Account *value;
} LedgerEntry;

typedef struct {
    LedgerEntry *entries;
    size_t size;
} Ledger;

void process_transactions() {
    Ledger ledger;
    ledger.entries = NULL;
    ledger.size = 0;

    while (1) {
        for (size_t i = 0; i < ledger.size; i++) {
            Account *data = ledger.entries[i].value;
            double balance = data->balance;
            balance += data->pending;
            data->balance = balance;
            data->pending = 0.0;
        }
    }
}

int main() {
    process_transactions();
    return 0;
}