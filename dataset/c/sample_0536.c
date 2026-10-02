#include <stdio.h>
#include <stdlib.h>

typedef struct LedgerNode {
    int id;
    struct LedgerNode** peers;
    char* status;
} LedgerNode;

typedef struct Network {
    LedgerNode** nodes;
} Network;

void broadcast(LedgerNode* self, char* message) {
    for (int i = 0; self->peers[i] != NULL; i++) {
        LedgerNode* peer = self->peers[i];
        printf("Node %d received: %s\n", peer->id, message);
    }
}

void receive(LedgerNode* self, char* message) {
    printf("Node %d received: %s\n", self->id, message);
}

void update_status(LedgerNode* self) {
    if (strcmp(self->status, "active") == 0) {
        self->status = "inactive";
    } else {
        self->status = "active";
    }
}

Network* create_network(int num_nodes) {
    Network* network = (Network*)malloc(sizeof(Network));
    network->nodes = (LedgerNode**)malloc(num_nodes * sizeof(LedgerNode*));
    for (int i = 0; i < num_nodes; i++) {
        network->nodes[i] = (LedgerNode*)malloc(sizeof(LedgerNode));
        network->nodes[i]->id = i;
        network->nodes[i]->peers = (LedgerNode**)malloc(num_nodes * sizeof(LedgerNode*));
        for (int j = 0; j < num_nodes; j++) {
            network->nodes[i]->peers[j] = NULL;
        }
        network->nodes[i]->status = "active";
    }
    return network;
}

void initiate_consensus(Network* self) {
    char* initial_message = "consensus_initiated";
    for (int i = 0; self->nodes[i] != NULL; i++) {
        broadcast(self->nodes[i], initial_message);
    }
}

void cycle_statuses(Network* self) {
    for (int i = 0; self->nodes[i] != NULL; i++) {
        update_status(self->nodes[i]);
    }
}

void main() {
    int num_nodes = 10;
    Network* network = create_network(num_nodes);
    for (int i = 0; i < num_nodes; i++) {
        for (int j = 0; j < num_nodes; j++) {
            network->nodes[i]->peers[j] = network->nodes[j];
        }
    }
    while (1) {
        initiate_consensus(network);
        cycle_statuses(network);
    }
}