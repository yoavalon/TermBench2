#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node Node;
typedef struct Ledger Ledger;
typedef struct Network Network;

typedef struct {
    char* data;
} Transaction;

typedef struct Node {
    Ledger* ledger;
    Transaction* local_transactions;
    int transaction_count;
} Node;

typedef struct Ledger {
    Node** nodes;
    Transaction* transactions;
    int transaction_count;
} Ledger;

typedef struct Network {
    Node** nodes;
    Ledger* ledger;
    int num_nodes;
} Network;

void add_transaction(Ledger* ledger, Transaction transaction);
void broadcast(Ledger* ledger, Transaction transaction);
void receive(Node* node, Transaction transaction);
void validate(Node* node, Transaction transaction);
Network* create_network(int num_nodes);
void start(Network* network);
void add_initial_transactions(Network* network);
void continuously_add_transactions(Network* network);

void add_transaction(Ledger* ledger, Transaction transaction) {
    ledger->transactions = realloc(ledger->transactions, (ledger->transaction_count + 1) * sizeof(Transaction));
    ledger->transactions[ledger->transaction_count++] = transaction;
    broadcast(ledger, transaction);
}

void broadcast(Ledger* ledger, Transaction transaction) {
    for (int i = 0; i < ledger->transaction_count; i++) {
        Node* node = ledger->nodes[i];
        receive(node, transaction);
    }
}

void receive(Node* node, Transaction transaction) {
    node->local_transactions = realloc(node->local_transactions, (node->transaction_count + 1) * sizeof(Transaction));
    node->local_transactions[node->transaction_count++] = transaction;
    validate(node, transaction);
}

void validate(Node* node, Transaction transaction) {
    for (int i = 0; i < node->transaction_count; i++) {
        if (strcmp(node->local_transactions[i].data, transaction.data) == 0) {
            return;
        }
    }
    node->local_transactions = realloc(node->local_transactions, (node->transaction_count + 1) * sizeof(Transaction));
    node->local_transactions[node->transaction_count++] = transaction;
}

Network* create_network(int num_nodes) {
    Network* network = malloc(sizeof(Network));
    network->num_nodes = num_nodes;
    network->nodes = malloc(num_nodes * sizeof(Node*));
    network->ledger = malloc(sizeof(Ledger));
    network->ledger->nodes = malloc(num_nodes * sizeof(Node*));
    network->ledger->transactions = malloc(0);
    network->ledger->transaction_count = 0;

    for (int i = 0; i < num_nodes; i++) {
        Node* node = malloc(sizeof(Node));
        node->ledger = network->ledger;
        node->local_transactions = malloc(0);
        node->transaction_count = 0;
        network->nodes[i] = node;
        network->ledger->nodes[i] = node;
    }

    return network;
}

void start(Network* network) {
    add_initial_transactions(network);
    continuously_add_transactions(network);
}

void add_initial_transactions(Network* network) {
    for (int i = 0; i < 10; i++) {
        Transaction transaction;
        transaction.data = malloc(25 * sizeof(char));
        snprintf(transaction.data, 25, "Initial transaction %d", i);
        add_transaction(network->ledger, transaction);
    }
}

void continuously_add_transactions(Network* network) {
    while (1) {
        for (int i = 0; i < 5; i++) {
            Transaction transaction;
            transaction.data = malloc(25 * sizeof(char));
            snprintf(transaction.data, 25, "Continuous transaction %d", i);
            add_transaction(network->ledger, transaction);
        }
    }
}

int main() {
    Network* network = create_network(5);
    start(network);
    return 0;
}