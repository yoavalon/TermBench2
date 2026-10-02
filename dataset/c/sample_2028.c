#include <stdio.h>
#include <stdlib.h>

typedef struct LedgerNode {
    double data;
    struct LedgerNode* next;
} LedgerNode;

typedef struct LedgerConsensus {
    LedgerNode* head;
    LedgerNode* tail;
} LedgerConsensus;

void LedgerConsensus_init(LedgerConsensus* ledger) {
    ledger->head = NULL;
    ledger->tail = NULL;
}

void LedgerConsensus_add_node(LedgerConsensus* ledger, double data) {
    LedgerNode* new_node = (LedgerNode*)malloc(sizeof(LedgerNode));
    new_node->data = data;
    new_node->next = NULL;
    if (!ledger->head) {
        ledger->head = new_node;
        ledger->tail = new_node;
    } else {
        ledger->tail->next = new_node;
        ledger->tail = new_node;
    }
}

int LedgerConsensus_validate_transactions(LedgerConsensus* ledger) {
    LedgerNode* current = ledger->head;
    while (current) {
        if (!LedgerConsensus_is_transaction_valid(current->data)) {
            return 0;
        }
        current = current->next;
    }
    return 1;
}

int LedgerConsensus_is_transaction_valid(double transaction) {
    return transaction > 0;
}

int process_ledger(double transactions[], int size) {
    LedgerConsensus ledger;
    LedgerConsensus_init(&ledger);
    for (int i = 0; i < size; i++) {
        LedgerConsensus_add_node(&ledger, transactions[i]);
    }
    return LedgerConsensus_validate_transactions(&ledger);
}

void main() {
    double transactions[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    int result = process_ledger(transactions, 5);
    printf("%d\n", result);
}