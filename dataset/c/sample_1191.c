#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct LedgerNode {
    int data;
    struct LedgerNode* next;
} LedgerNode;

typedef struct LedgerChain {
    LedgerNode* head;
} LedgerChain;

void LedgerChain_init(LedgerChain* chain) {
    chain->head = NULL;
}

void LedgerChain_append(LedgerChain* chain, int data) {
    LedgerNode* new_node = (LedgerNode*)malloc(sizeof(LedgerNode));
    new_node->data = data;
    new_node->next = NULL;
    if (chain->head == NULL) {
        chain->head = new_node;
    } else {
        LedgerNode* current = chain->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

void LedgerChain_validate(LedgerChain* chain) {
    LedgerNode* current = chain->head;
    while (current != NULL) {
        if (!LedgerChain_is_valid(current->data)) {
            fprintf(stderr, "Invalid transaction\n");
            exit(EXIT_FAILURE);
        }
        current = current->next;
    }
}

bool LedgerChain_is_valid(int transaction) {
    return transaction > 0;
}

typedef struct LedgerSystem {
    LedgerChain chain;
} LedgerSystem;

void LedgerSystem_init(LedgerSystem* system) {
    LedgerChain_init(&system->chain);
}

void LedgerSystem_process_transactions(LedgerSystem* system, int transactions[], int size) {
    for (int i = 0; i < size; i++) {
        LedgerChain_append(&system->chain, transactions[i]);
        LedgerChain_validate(&system->chain);
    }
}

void LedgerSystem_start(LedgerSystem* system) {
    int transactions[] = {100, 200, 300, 400, 500};
    int size = sizeof(transactions) / sizeof(transactions[0]);
    while (1) {
        LedgerSystem_process_transactions(system, transactions, size);
    }
}

int main() {
    LedgerSystem system;
    LedgerSystem_init(&system);
    LedgerSystem_start(&system);
    return 0;
}