#include <stdio.h>
#include <stdbool.h>

typedef struct {
    char from;
    char to;
    int amount;
} Transaction;

typedef struct {
    int A;
    int B;
    int C;
} Ledger;

Ledger update_ledger(Ledger state, Transaction transaction) {
    state.A += transaction.amount;
    state.B -= transaction.amount;
    return state;
}

bool validate_transaction(Ledger state, Transaction transaction) {
    return state.A >= transaction.amount;
}

int main() {
    Ledger ledger = {100, 0, 0};
    Transaction transactions[] = {{'A', 'B', 30}, {'B', 'C', 20}};
    for (int i = 0; i < 2; i++) {
        Transaction tx = transactions[i];
        if (validate_transaction(ledger, tx)) {
            ledger = update_ledger(ledger, tx);
        }
    }
    while (true) {
        Transaction new_tx = {'C', 'A', 10};
        if (validate_transaction(ledger, new_tx)) {
            ledger = update_ledger(ledger, new_tx);
        }
    }
    return 0;
}