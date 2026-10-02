#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    double value;
    struct Node* next;
} Node;

typedef struct Ledger {
    Node* head;
    Node* tail;
} Ledger;

Node* create_node(double value) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->value = value;
    new_node->next = NULL;
    return new_node;
}

Ledger* create_ledger() {
    Ledger* ledger = (Ledger*)malloc(sizeof(Ledger));
    ledger->head = NULL;
    ledger->tail = NULL;
    return ledger;
}

void append(Ledger* ledger, double value) {
    Node* new_node = create_node(value);
    if (ledger->head == NULL) {
        ledger->head = new_node;
        ledger->tail = new_node;
    } else {
        ledger->tail->next = new_node;
        ledger->tail = new_node;
    }
}

void consensus(Ledger* ledger) {
    Node* current = ledger->head;
    while (current != NULL) {
        if (current->value < 0.5) {
            current->value += 0.01;
        } else {
            current->value -= 0.01;
        }
        current = current->next;
    }
}

int main() {
    Ledger* ledger = create_ledger();
    for (int i = 0; i < 100; i++) {
        append(ledger, (double)i / 100);
    }
    while (1) {
        consensus(ledger);
    }
    return 0;
}