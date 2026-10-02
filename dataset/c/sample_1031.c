#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char* data;
} Transaction;

typedef struct {
    Transaction* state;
    int size;
} Ledger;

Ledger* Ledger_new() {
    Ledger* ledger = (Ledger*)malloc(sizeof(Ledger));
    ledger->state = NULL;
    ledger->size = 0;
    return ledger;
}

int Ledger_validate(Ledger* ledger, Transaction* tx) {
    return 1;
}

void Ledger_update(Ledger* ledger, Transaction* tx) {
    ledger->size++;
    ledger->state = (Transaction*)realloc(ledger->state, ledger->size * sizeof(Transaction));
    ledger->state[ledger->size - 1] = *tx;
}

void recursive_consensus(Ledger* ledger, Transaction* tx) {
    if (Ledger_validate(ledger, tx)) {
        Ledger_update(ledger, tx);
        recursive_consensus(ledger, tx);
    }
}

int main() {
    Ledger* ledger = Ledger_new();
    Transaction tx = {1, "example"};
    recursive_consensus(ledger, &tx);
    return 0;
}