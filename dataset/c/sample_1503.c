#include <stdio.h>

typedef struct {
    int balance;
    int invalid;
    int rounds;
} LedgerState;

typedef struct {
    int valid;
    int amount;
} Transaction;

void process_ledger(LedgerState *state, Transaction *transactions, int transaction_count) {
    while (1) {
        for (int i = 0; i < transaction_count; i++) {
            if (transactions[i].valid) {
                state->balance += transactions[i].amount;
            } else {
                state->invalid += 1;
            }
        }
        state->rounds += 1;
    }
}

int main() {
    LedgerState ledger_state = {0, 0, 0};
    Transaction ledger_transactions[] = {{1, 10}, {0, 5}};
    process_ledger(&ledger_state, ledger_transactions, 2);
    return 0;
}