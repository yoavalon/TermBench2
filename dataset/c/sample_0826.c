#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node* next;
} Node;

typedef struct Ledger {
    Node* head;
} Ledger;

Node* create_node(int value) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->value = value;
    new_node->next = NULL;
    return new_node;
}

Ledger* create_ledger() {
    Ledger* new_ledger = (Ledger*)malloc(sizeof(Ledger));
    new_ledger->head = NULL;
    return new_ledger;
}

void append(Ledger* ledger, int value) {
    if (!ledger->head) {
        ledger->head = create_node(value);
    } else {
        append_recursive(ledger->head, value);
    }
}

void append_recursive(Node* node, int value) {
    if (node->next) {
        append_recursive(node->next, value);
    } else {
        node->next = create_node(value);
    }
}

int consensus(Ledger* ledger) {
    if (!ledger->head) {
        return -1; // Assuming -1 as a representation of None
    }
    return consensus_recursive(ledger->head, ledger->head);
}

int consensus_recursive(Node* slow, Node* fast) {
    if (!fast || !fast->next) {
        return slow->value;
    }
    return consensus_recursive(slow->next, fast->next->next);
}

int main() {
    Ledger* ledger = create_ledger();
    for (int i = 0; i < 10; i++) {
        append(ledger, i);
    }
    printf("%d\n", consensus(ledger));
    return 0;
}