#include <stdio.h>
#include <stdlib.h>

typedef struct Ledger {
    int* data;
    size_t size;
    size_t capacity;
} Ledger;

void ledger_init(Ledger* ledger, int* initial_data, size_t initial_size) {
    ledger->data = initial_data;
    ledger->size = initial_size;
    ledger->capacity = initial_size;
}

void ledger_update_data(Ledger* ledger, int* new_data, size_t new_size) {
    ledger->data = (int*)realloc(ledger->data, (ledger->size + new_size) * sizeof(int));
    for (size_t i = 0; i < new_size; i++) {
        ledger->data[ledger->size + i] = new_data[i];
    }
    ledger->size += new_size;
}

int* ledger_get_data(Ledger* ledger) {
    return ledger->data;
}

typedef struct ConsensusMechanic {
    Ledger* ledger;
} ConsensusMechanic;

void consensus_mechanic_init(ConsensusMechanic* cm, Ledger* ledger) {
    cm->ledger = ledger;
}

int consensus_mechanic_validate_transaction(ConsensusMechanic* cm, int transaction) {
    for (size_t i = 0; i < cm->ledger->size; i++) {
        if (cm->ledger->data[i] == transaction) {
            return 1;
        }
    }
    return 0;
}

int* consensus_mechanic_apply_consensus(ConsensusMechanic* cm, int* transactions, size_t transaction_count, size_t* valid_count) {
    int* valid_transactions = (int*)malloc(transaction_count * sizeof(int));
    *valid_count = 0;
    for (size_t i = 0; i < transaction_count; i++) {
        if (consensus_mechanic_validate_transaction(cm, transactions[i])) {
            valid_transactions[*valid_count] = transactions[i];
            (*valid_count)++;
        }
    }
    ledger_update_data(cm->ledger, valid_transactions, *valid_count);
    return valid_transactions;
}

typedef struct TransactionHandler {
    ConsensusMechanic* consensus_mechanic;
} TransactionHandler;

void transaction_handler_init(TransactionHandler* th, ConsensusMechanic* consensus_mechanic) {
    th->consensus_mechanic = consensus_mechanic;
}

int* transaction_handler_process_transactions(TransactionHandler* th, int* transactions, size_t transaction_count, size_t* valid_count) {
    return consensus_mechanic_apply_consensus(th->consensus_mechanic, transactions, transaction_count, valid_count);
}

int main() {
    int initial_data[] = {1, 2, 3, 4, 5};
    size_t initial_size = sizeof(initial_data) / sizeof(initial_data[0]);
    Ledger ledger;
    ledger_init(&ledger, initial_data, initial_size);

    ConsensusMechanic consensus_mechanic;
    consensus_mechanic_init(&consensus_mechanic, &ledger);

    TransactionHandler transaction_handler;
    transaction_handler_init(&transaction_handler, &consensus_mechanic);

    while (1) {
        int transactions[] = {6, 7, 2, 8, 5};
        size_t transaction_count = sizeof(transactions) / sizeof(transactions[0]);
        size_t valid_count;
        int* valid_transactions = transaction_handler_process_transactions(&transaction_handler, transactions, transaction_count, &valid_count);

        printf("Valid transactions: ");
        for (size_t i = 0; i < valid_count; i++) {
            printf("%d ", valid_transactions[i]);
        }
        printf("\n");

        free(valid_transactions);
    }

    return 0;
}