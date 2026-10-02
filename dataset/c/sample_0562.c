#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int id;
    int value;
    struct Node* next;
} Node;

typedef struct Ledger {
    Node* head;
} Ledger;

void Node_init(Node* node, int id, int value) {
    node->id = id;
    node->value = value;
    node->next = NULL;
}

void Ledger_init(Ledger* ledger) {
    ledger->head = NULL;
}

void Ledger_append(Ledger* ledger, int value) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    Node_init(new_node, Ledger_len(ledger) + 1, value);
    if (ledger->head == NULL) {
        ledger->head = new_node;
    } else {
        Node* current = ledger->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

int Ledger_len(Ledger* ledger) {
    int count = 0;
    Node* current = ledger->head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

bool Ledger_validate(Ledger* ledger) {
    Node* current = ledger->head;
    while (current != NULL) {
        if (current->value < 0) {
            return false;
        }
        current = current->next;
    }
    return true;
}

void simulate_consensus(Ledger* ledger) {
    while (1) {
        Ledger_append(ledger, Ledger_len(ledger) * 2);
        if (!Ledger_validate(ledger)) {
            fprintf(stderr, "Validation failed\n");
            exit(1);
        }
    }
}

int main() {
    Ledger ledger;
    Ledger_init(&ledger);
    simulate_consensus(&ledger);
    return 0;
}