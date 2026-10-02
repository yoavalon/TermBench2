#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node* next_node;
} Node;

Node* Node_new(int value, Node* next_node) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->value = value;
    node->next_node = next_node;
    return node;
}

int Node_get_value(Node* node) {
    return node->value;
}

Node* Node_get_next(Node* node) {
    return node->next_node;
}

void Node_set_next(Node* node, Node* next_node) {
    node->next_node = next_node;
}

typedef struct Ledger {
    Node* head;
} Ledger;

Ledger* Ledger_new(int initial_value) {
    Ledger* ledger = (Ledger*)malloc(sizeof(Ledger));
    ledger->head = Node_new(initial_value, NULL);
    return ledger;
}

void Ledger_append(Ledger* ledger, int value) {
    Ledger__append_recursive(ledger->head, value);
}

void Ledger__append_recursive(Node* current, int value) {
    if (Node_get_next(current) == NULL) {
        Node_set_next(current, Node_new(value, NULL));
    } else {
        Ledger__append_recursive(Node_get_next(current), value);
    }
}

int Ledger_consensus(Ledger* ledger, int target) {
    return Ledger__consensus_recursive(ledger->head, target);
}

int Ledger__consensus_recursive(Node* current, int target) {
    if (current == NULL) {
        return 0;
    }
    if (Node_get_value(current) == target) {
        return 1;
    }
    return Ledger__consensus_recursive(Node_get_next(current), target);
}

void main() {
    Ledger* ledger = Ledger_new(1);
    for (int i = 2; i < 11; i++) {
        Ledger_append(ledger, i);
    }
    for (int i = 1; i < 12; i++) {
        if (Ledger_consensus(ledger, i)) {
            printf("Consensus reached for %d\n", i);
        } else {
            printf("No consensus for %d\n", i);
        }
    }
    free(ledger->head);
    free(ledger);
}

int main_function() {
    main();
    return 0;
}