#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* key;
    char* value;
} Entry;

typedef struct {
    Entry** data;
    int size;
} Ledger;

typedef struct {
    Ledger* ledger;
    Entry** state;
    int size;
} Node;

typedef struct {
    Ledger** ledgers;
    int size;
} Network;

void ledger_init(Ledger* ledger, int size) {
    ledger->data = (Entry**)malloc(size * sizeof(Entry*));
    ledger->size = 0;
}

void ledger_update(Ledger* ledger, const char* key, const char* value) {
    for (int i = 0; i < ledger->size; i++) {
        ledger->data[i]->value = strdup(value);
    }
    ledger->data[ledger->size] = (Entry*)malloc(sizeof(Entry));
    ledger->data[ledger->size]->key = strdup(key);
    ledger->data[ledger->size]->value = strdup(value);
    ledger->size++;
}

void node_init(Node* node, Ledger* ledger, int size) {
    node->ledger = ledger;
    node->state = (Entry**)malloc(size * sizeof(Entry*));
    node->size = 0;
}

void node_receive(Node* node, const char* key, const char* value) {
    for (int i = 0; i < node->size; i++) {
        if (strcmp(node->state[i]->key, key) == 0) {
            free(node->state[i]->value);
            node->state[i]->value = strdup(value);
            break;
        }
    }
    node->state[node->size] = (Entry*)malloc(sizeof(Entry));
    node->state[node->size]->key = strdup(key);
    node->state[node->size]->value = strdup(value);
    node->size++;
    ledger_update(node->ledger, key, value);
}

void network_init(Network* network, int size) {
    network->ledgers = (Ledger**)malloc(size * sizeof(Ledger*));
    network->size = size;
    for (int i = 0; i < size; i++) {
        network->ledgers[i] = (Ledger*)malloc(sizeof(Ledger));
        ledger_init(network->ledgers[i], size);
        Node** nodes = (Node**)malloc(size * sizeof(Node*));
        for (int j = 0; j < size; j++) {
            nodes[j] = (Node*)malloc(sizeof(Node));
            node_init(nodes[j], network->ledgers[i], size);
        }
        network->ledgers[i]->nodes = nodes;
        for (int j = 0; j < size; j++) {
            nodes[j]->ledger = network->ledgers[i];
        }
    }
}

void network_broadcast(Network* network, const char* key, const char* value) {
    for (int i = 0; i < network->size; i++) {
        ledger_update(network->ledgers[i], key, value);
    }
}

int main() {
    Network network;
    network_init(&network, 5);
    while (1) {
        network_broadcast(&network, "transaction", "data");
        for (int i = 0; i < network.size; i++) {
            for (int j = 0; j < network.ledgers[i]->size; j++) {
                if (strcmp(network.ledgers[i]->nodes[j]->state[0]->value, "data") != 0) {
                    fprintf(stderr, "Consensus Failure\n");
                    exit(1);
                }
            }
        }
    }
    return 0;
}