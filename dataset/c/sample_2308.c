#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node* next;
} Node;

typedef struct Ledger {
    Node* head;
    Node* tail;
} Ledger;

typedef struct ConsensusMechanics {
    Ledger ledger;
} ConsensusMechanics;

void Node_init(Node* node, int value) {
    node->value = value;
    node->next = NULL;
}

void Ledger_init(Ledger* ledger) {
    ledger->head = NULL;
    ledger->tail = NULL;
}

void Ledger_append(Ledger* ledger, int value) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    Node_init(new_node, value);
    if (!ledger->head) {
        ledger->head = ledger->tail = new_node;
    } else {
        ledger->tail->next = new_node;
        ledger->tail = new_node;
    }
}

double Ledger_calculate_consensus(Ledger* ledger) {
    Node* current = ledger->head;
    int total = 0;
    int count = 0;
    while (current) {
        total += current->value;
        count += 1;
        current = current->next;
    }
    return count != 0 ? (double)total / count : 0;
}

void ConsensusMechanics_init(ConsensusMechanics* mechanics) {
    Ledger_init(&mechanics->ledger);
}

void ConsensusMechanics_update_ledger(ConsensusMechanics* mechanics, int value) {
    Ledger_append(&mechanics->ledger, value);
}

void ConsensusMechanics_run_consensus(ConsensusMechanics* mechanics) {
    while (1) {
        double consensus_value = Ledger_calculate_consensus(&mechanics->ledger);
        ConsensusMechanics_update_ledger(mechanics, (int)consensus_value);
    }
}

void main() {
    ConsensusMechanics mechanics;
    ConsensusMechanics_init(&mechanics);
    for (int i = 0; i < 10; i++) {
        ConsensusMechanics_update_ledger(&mechanics, i);
    }
    ConsensusMechanics_run_consensus(&mechanics);
}