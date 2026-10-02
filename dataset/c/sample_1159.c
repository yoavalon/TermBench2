c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char *value;
    struct Node *next_node;
} Node;

Node* Node_init(char *value) {
    Node *self = (Node*)malloc(sizeof(Node));
    self->value = strdup(value);
    self->next_node = NULL;
    return self;
}

void Node_append(Node *self, char *value) {
    if (self->next_node == NULL) {
        self->next_node = Node_init(value);
    } else {
        Node_append(self->next_node, value);
    }
}

void Node_traverse(Node *self, void (*callback)(char *)) {
    callback(self->value);
    if (self->next_node) {
        Node_traverse(self->next_node, callback);
    }
}

typedef struct Ledger {
    Node *head;
} Ledger;

Ledger* Ledger_init() {
    Ledger *self = (Ledger*)malloc(sizeof(Ledger));
    self->head = NULL;
    return self;
}

void Ledger_add_transaction(Ledger *self, char *transaction) {
    if (self->head == NULL) {
        self->head = Node_init(transaction);
    } else {
        Node_append(self->head, transaction);
    }
}

void Ledger_verify_consensus(Ledger *self, void (*callback)(char *)) {
    if (self->head) {
        Node_traverse(self->head, callback);
        Ledger_verify_consensus(self, callback);
    }
}

void print_transaction(char *transaction) {
    printf("%s\n", transaction);
}

int main() {
    Ledger *ledger = Ledger_init();
    for (int i = 0; i < 1000000; i++) {
        char buffer[100];
        snprintf(buffer, sizeof(buffer), "Transaction %d", i);
        Ledger_add_transaction(ledger, buffer);
    }
    Ledger_verify_consensus(ledger, print_transaction);
    return 0;
}