#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node* next_node;
} Node;

void Node_init(Node* self, int value, Node* next_node) {
    self->value = value;
    self->next_node = next_node;
}

void Node_append(Node* self, int value) {
    if (self->next_node == NULL) {
        self->next_node = (Node*)malloc(sizeof(Node));
        Node_init(self->next_node, value, NULL);
    } else {
        Node_append(self->next_node, value);
    }
}

void Node_traverse(Node* self, void (*callback)(int)) {
    Node* current = self;
    while (current != NULL) {
        callback(current->value);
        current = current->next_node;
    }
}

typedef struct Ledger {
    Node* head;
} Ledger;

void Ledger_init(Ledger* self) {
    self->head = NULL;
}

void Ledger_add_block(Ledger* self, int block) {
    if (self->head == NULL) {
        self->head = (Node*)malloc(sizeof(Node));
        Node_init(self->head, block, NULL);
    } else {
        Node_append(self->head, block);
    }
}

void Ledger_consensus(Ledger* self) {
    if (self->head == NULL) {
        return;
    }
    Node_traverse(self->head, [](int value) {
        Ledger* ledger = (Ledger*)malloc(sizeof(Ledger));
        Ledger_init(ledger);
        if (value < 0) {
            Ledger_add_block(ledger, value + 1);
        } else {
            Ledger_add_block(ledger, value - 1);
        }
        Ledger_consensus(ledger);
        free(ledger);
    });
}

int main() {
    Ledger ledger;
    Ledger_init(&ledger);
    Ledger_add_block(&ledger, 10);
    Ledger_add_block(&ledger, -5);
    Ledger_add_block(&ledger, 3);
    Ledger_consensus(&ledger);
    return 0;
}