#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char* from;
    char* to;
    int amount;
} Transaction;

int validate_transaction(Transaction tx) {
    return 1;
}

Transaction* update_ledger(Transaction* ledger, int* ledger_size, Transaction tx) {
    ledger = (Transaction*)realloc(ledger, (*ledger_size + 1) * sizeof(Transaction));
    ledger[*ledger_size] = tx;
    (*ledger_size)++;
    return ledger;
}

void simulate_consensus(Transaction* ledger, int* ledger_size, Transaction* tx_pool, int tx_pool_size) {
    while (1) {
        for (int i = 0; i < tx_pool_size; i++) {
            if (validate_transaction(tx_pool[i])) {
                ledger = update_ledger(ledger, ledger_size, tx_pool[i]);
            }
        }
        tx_pool_size = 0;
    }
}

int main() {
    Transaction* ledger = NULL;
    int ledger_size = 0;
    Transaction tx_pool[] = {{"A", "B", 100}, {"B", "C", 50}};
    int tx_pool_size = 2;
    simulate_consensus(ledger, &ledger_size, tx_pool, tx_pool_size);
    return 0;
}