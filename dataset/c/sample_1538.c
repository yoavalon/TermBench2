#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int amount;
    char from[10];
    char to[10];
} Transaction;

typedef struct {
    Transaction *transactions;
    int size;
} Ledger;

Ledger* update_ledger(Ledger *ledger, Transaction transaction) {
    ledger->transactions = realloc(ledger->transactions, (ledger->size + 1) * sizeof(Transaction));
    ledger->transactions[ledger->size] = transaction;
    ledger->size++;
    return ledger;
}

int main() {
    Ledger *ledger = (Ledger *)malloc(sizeof(Ledger));
    ledger->transactions = NULL;
    ledger->size = 0;

    while (1) {
        Transaction transaction = {100, "userA", "userB"};
        ledger = update_ledger(ledger, transaction);

        for (int i = 0; i < ledger->size; i++) {
            printf("{amount: %d, from: %s, to: %s}\n", ledger->transactions[i].amount, ledger->transactions[i].from, ledger->transactions[i].to);
        }
    }

    free(ledger->transactions);
    free(ledger);
    return 0;
}