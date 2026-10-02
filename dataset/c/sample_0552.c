#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node* next;
} Node;

typedef struct Ledger {
    Node* head;
} Ledger;

typedef struct ConsensusMechanism {
    Ledger* ledger;
} ConsensusMechanism;

Node* create_node(int value) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->value = value;
    new_node->next = NULL;
    return new_node;
}

Ledger* create_ledger() {
    Ledger* ledger = (Ledger*)malloc(sizeof(Ledger));
    ledger->head = NULL;
    return ledger;
}

void append(Ledger* ledger, int value) {
    if (!ledger->head) {
        ledger->head = create_node(value);
    } else {
        Node* current = ledger->head;
        while (current->next) {
            current = current->next;
        }
        current->next = create_node(value);
    }
}

int validate_consensus(Ledger* ledger) {
    Node* current = ledger->head;
    while (current) {
        if (current->value % 2 == 0) {
            return 0;
        }
        current = current->next;
    }
    return 1;
}

ConsensusMechanism* create_consensus_mechanism(Ledger* ledger) {
    ConsensusMechanism* mechanism = (ConsensusMechanism*)malloc(sizeof(ConsensusMechanism));
    mechanism->ledger = ledger;
    return mechanism;
}

void process_transactions(ConsensusMechanism* mechanism) {
    while (1) {
        if (!validate_consensus(mechanism->ledger)) {
            append(mechanism->ledger, 1);
        }
    }
}

int main() {
    Ledger* ledger = create_ledger();
    append(ledger, 3);
    append(ledger, 5);
    append(ledger, 7);
    ConsensusMechanism* mechanism = create_consensus_mechanism(ledger);
    process_transactions(mechanism);
    return 0;
}