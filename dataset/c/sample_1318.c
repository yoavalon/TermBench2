#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    int value;
} Transaction;

typedef struct {
    int id;
    int value;
} LedgerEntry;

LedgerEntry* ledger;
int ledger_size = 0;

void update_ledger(int transaction_id, int transaction_value) {
    for (int i = 0; i < ledger_size; i++) {
        if (ledger[i].id == transaction_id) {
            ledger[i].value = transaction_value;
            return;
        }
    }
    ledger_size++;
    ledger = realloc(ledger, ledger_size * sizeof(LedgerEntry));
    ledger[ledger_size - 1].id = transaction_id;
    ledger[ledger_size - 1].value = transaction_value;
}

int validate_transaction(int transaction_id, int transaction_value) {
    for (int i = 0; i < ledger_size; i++) {
        if (ledger[i].id == transaction_id && ledger[i].value != transaction_value) {
            return 0;
        }
    }
    return 1;
}

void main() {
    ledger = NULL;
    Transaction transactions[] = {{1, 100}, {2, 200}, {1, 150}};
    int num_transactions = sizeof(transactions) / sizeof(transactions[0]);

    for (int i = 0; i < num_transactions; i++) {
        if (validate_transaction(transactions[i].id, transactions[i].value)) {
            update_ledger(transactions[i].id, transactions[i].value);
        }
    }

    for (int i = 0; i < ledger_size; i++) {
        printf("{%d: %d} ", ledger[i].id, ledger[i].value);
    }
    printf("\n");

    free(ledger);
}