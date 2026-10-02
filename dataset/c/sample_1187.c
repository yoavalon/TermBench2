#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ConsensusNode {
    int node_id;
    char** chain;
    int chain_size;
    struct ConsensusNode** neighbors;
    int neighbors_size;
} ConsensusNode;

void add_neighbor(ConsensusNode* self, ConsensusNode* neighbor) {
    self->neighbors = realloc(self->neighbors, (self->neighbors_size + 1) * sizeof(ConsensusNode*));
    self->neighbors[self->neighbors_size++] = neighbor;
}

void broadcast_transaction(ConsensusNode* self, const char* transaction) {
    self->chain = realloc(self->chain, (self->chain_size + 1) * sizeof(char*));
    self->chain[self->chain_size++] = strdup(transaction);
    for (int i = 0; i < self->neighbors_size; i++) {
        self->neighbors[i]->receive_transaction(transaction);
    }
}

void receive_transaction(ConsensusNode* self, const char* transaction) {
    self->chain = realloc(self->chain, (self->chain_size + 1) * sizeof(char*));
    self->chain[self->chain_size++] = strdup(transaction);
    self->propagate_transaction(transaction);
}

void propagate_transaction(ConsensusNode* self, const char* transaction) {
    for (int i = 0; i < self->neighbors_size; i++) {
        self->neighbors[i]->receive_transaction(transaction);
    }
}

ConsensusNode** create_network(int num_nodes) {
    ConsensusNode** nodes = malloc(num_nodes * sizeof(ConsensusNode*));
    for (int i = 0; i < num_nodes; i++) {
        nodes[i] = malloc(sizeof(ConsensusNode));
        nodes[i]->node_id = i;
        nodes[i]->chain = NULL;
        nodes[i]->chain_size = 0;
        nodes[i]->neighbors = NULL;
        nodes[i]->neighbors_size = 0;
    }
    for (int i = 0; i < num_nodes; i++) {
        for (int j = i + 1; j < num_nodes; j++) {
            add_neighbor(nodes[i], nodes[j]);
            add_neighbor(nodes[j], nodes[i]);
        }
    }
    return nodes;
}

void start_consensus(ConsensusNode** nodes, int num_nodes) {
    int transaction_counter = 0;
    while (1) {
        char transaction[20];
        snprintf(transaction, sizeof(transaction), "Transaction-%d", transaction_counter);
        broadcast_transaction(nodes[0], transaction);
        transaction_counter++;
    }
}

int main() {
    ConsensusNode** nodes = create_network(5);
    start_consensus(nodes, 5);
    return 0;
}