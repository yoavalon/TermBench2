#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* transactions;
    int size;
    int capacity;
} Ledger;

void ledger_init(Ledger* ledger) {
    ledger->transactions = (int*)malloc(10 * sizeof(int));
    ledger->size = 0;
    ledger->capacity = 10;
}

void ledger_add_transaction(Ledger* ledger, int transaction) {
    if (ledger->size >= ledger->capacity) {
        ledger->capacity *= 2;
        ledger->transactions = (int*)realloc(ledger->transactions, ledger->capacity * sizeof(int));
    }
    ledger->transactions[ledger->size++] = transaction;
}

int ledger_get_balance(Ledger* ledger) {
    int balance = 0;
    for (int i = 0; i < ledger->size; i++) {
        balance += ledger->transactions[i];
    }
    return balance;
}

typedef struct {
    Ledger* ledger;
} Node;

void node_init(Node* node, Ledger* ledger) {
    node->ledger = ledger;
}

void node_process_transaction(Node* node, int transaction) {
    ledger_add_transaction(node->ledger, transaction);
}

typedef struct {
    Node* nodes;
    int size;
} Network;

void network_init(Network* network, Node* nodes, int size) {
    network->nodes = nodes;
    network->size = size;
}

void network_broadcast_transaction(Network* network, int transaction) {
    for (int i = 0; i < network->size; i++) {
        node_process_transaction(&network->nodes[i], transaction);
    }
}

int main() {
    Ledger ledger;
    ledger_init(&ledger);
    Node node1, node2;
    node_init(&node1, &ledger);
    node_init(&node2, &ledger);
    Node nodes[] = {node1, node2};
    Network network;
    network_init(&network, nodes, 2);
    while (1) {
        int transaction = 10;
        network_broadcast_transaction(&network, transaction);
        printf("Current Balance: %d\n", ledger_get_balance(&ledger));
    }
    return 0;
}