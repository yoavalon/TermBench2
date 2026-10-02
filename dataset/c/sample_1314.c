#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char validator;
    void *state;
} Transaction;

typedef struct {
    Transaction *transactions;
    int size;
    int capacity;
} Ledger;

void update_ledger(Ledger *state, Transaction transaction) {
    if (state->size == state->capacity) {
        state->capacity = state->capacity ? state->capacity * 2 : 1;
        state->transactions = (Transaction *)realloc(state->transactions, state->capacity * sizeof(Transaction));
    }
    state->transactions[state->size++] = transaction;
}

Ledger *consensus_round(Ledger *state, char *validators, int validator_count) {
    int quorum = validator_count / 2 + 1;
    for (int i = 0; i < quorum; i++) {
        Transaction transaction;
        transaction.validator = validators[--validator_count];
        transaction.state = state;
        update_ledger(state, transaction);
    }
    return state;
}

int main() {
    Ledger state = {NULL, 0, 0};
    char validators[] = {'A', 'B', 'C', 'D', 'E'};
    int validator_count = sizeof(validators) / sizeof(validators[0]);

    for (int i = 0; i < 3; i++) {
        state = *consensus_round(&state, validators, validator_count);
    }

    for (int i = 0; i < state.size; i++) {
        printf("{validator: %c, state: %p}\n", state.transactions[i].validator, state.transactions[i].state);
    }

    free(state.transactions);
    return 0;
}