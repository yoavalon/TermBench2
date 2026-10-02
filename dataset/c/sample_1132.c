#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char* data;
    struct Node* next;
} Node;

typedef struct Ledger {
    Node* head;
} Ledger;

void Node_init(Node* node, char* data) {
    node->data = strdup(data);
    node->next = NULL;
}

void Ledger_init(Ledger* ledger) {
    ledger->head = NULL;
}

void Ledger_append(Ledger* ledger, char* data) {
    if (!ledger->head) {
        ledger->head = (Node*)malloc(sizeof(Node));
        Node_init(ledger->head, data);
    } else {
        Node* current = ledger->head;
        while (current->next) {
            current = current->next;
        }
        current->next = (Node*)malloc(sizeof(Node));
        Node_init(current->next, data);
    }
}

int Ledger_verify(Ledger* ledger, Node* node) {
    if (node->next) {
        return Ledger_verify(ledger, node->next);
    }
    return 1;
}

typedef struct Consensus {
    Ledger* ledger;
} Consensus;

void Consensus_init(Consensus* consensus, Ledger* ledger) {
    consensus->ledger = ledger;
}

void Consensus_start(Consensus* consensus) {
    while (1) {
        Ledger_append(consensus->ledger, "transaction");
        if (!Ledger_verify(consensus->ledger, consensus->ledger->head)) {
            break;
        }
    }
}

int main() {
    Ledger ledger;
    Ledger_init(&ledger);
    Consensus consensus;
    Consensus_init(&consensus, &ledger);
    Consensus_start(&consensus);
    return 0;
}