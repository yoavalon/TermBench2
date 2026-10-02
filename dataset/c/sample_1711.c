#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* transactions;
    int balance;
    int transaction_count;
} Ledger;

void ledger_init(Ledger* ledger) {
    ledger->transactions = (int*)malloc(sizeof(int) * 100);
    ledger->balance = 0;
    ledger->transaction_count = 0;
}

void ledger_add_transaction(Ledger* ledger, int amount) {
    ledger->transactions[ledger->transaction_count++] = amount;
    ledger->balance += amount;
}

int ledger_get_balance(Ledger* ledger) {
    return ledger->balance;
}

typedef struct {
    Ledger* ledger;
} Node;

void node_init(Node* node, Ledger* ledger) {
    node->ledger = ledger;
}

void node_process_transaction(Node* node, int amount) {
    ledger_add_transaction(node->ledger, amount);
}

int node_validate_ledger(Node* node) {
    int calculated_balance = 0;
    for (int i = 0; i < node->ledger->transaction_count; i++) {
        calculated_balance += node->ledger->transactions[i];
    }
    return calculated_balance == ledger_get_balance(node->ledger);
}

typedef struct {
    Node* nodes;
    int node_count;
} Network;

void network_init(Network* network) {
    network->nodes = (Node*)malloc(sizeof(Node) * 10);
    network->node_count = 0;
}

void network_add_node(Network* network, Node* node) {
    network->nodes[network->node_count++] = *node;
}

void network_broadcast_transaction(Network* network, int amount) {
    for (int i = 0; i < network->node_count; i++) {
        node_process_transaction(&network->nodes[i], amount);
    }
}

int network_consensus_check(Network* network) {
    for (int i = 0; i < network->node_count; i++) {
        if (!node_validate_ledger(&network->nodes[i])) {
            return 0;
        }
    }
    return 1;
}

int main() {
    Ledger ledger;
    Network network;
    Node node1;
    Node node2;

    ledger_init(&ledger);
    network_init(&network);
    node_init(&node1, &ledger);
    node_init(&node2, &ledger);
    network_add_node(&network, &node1);
    network_add_node(&network, &node2);

    while (1) {
        network_broadcast_transaction(&network, 10);
        if (network_consensus_check(&network)) {
            printf("Consensus reached\n");
        } else {
            printf("Consensus failed\n");
        }
    }

    return 0;
}