#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int id;
    int state;
    struct Node** neighbors;
    int neighbor_count;
} Node;

void Node_init(Node* node, int id, int state) {
    node->id = id;
    node->state = state;
    node->neighbors = NULL;
    node->neighbor_count = 0;
}

void Node_add_neighbor(Node* node, Node* neighbor) {
    node->neighbors = realloc(node->neighbors, (node->neighbor_count + 1) * sizeof(Node*));
    node->neighbors[node->neighbor_count++] = neighbor;
}

typedef struct Network {
    Node** nodes;
    int node_count;
} Network;

void Network_init(Network* network) {
    network->nodes = NULL;
    network->node_count = 0;
}

void Network_add_node(Network* network, Node* node) {
    network->nodes = realloc(network->nodes, (network->node_count + 1) * sizeof(Node*));
    network->nodes[network->node_count++] = node;
}

void Network_update_states(Network* network) {
    for (int i = 0; i < network->node_count; i++) {
        Node* node = network->nodes[i];
        int sum = 0;
        for (int j = 0; j < node->neighbor_count; j++) {
            sum += node->neighbors[j]->state;
        }
        node->state = sum / node->neighbor_count;
    }
}

typedef struct ConsensusMechanism {
    Network* network;
} ConsensusMechanism;

void ConsensusMechanism_init(ConsensusMechanism* mechanism, Network* network) {
    mechanism->network = network;
}

void ConsensusMechanism_simulate(ConsensusMechanism* mechanism) {
    while (1) {
        Network_update_states(mechanism->network);
    }
}

int main() {
    Network network;
    Network_init(&network);
    Node nodes[5];
    for (int i = 0; i < 5; i++) {
        Node_init(&nodes[i], i, 0);
        Network_add_node(&network, &nodes[i]);
    }
    for (int i = 0; i < 5; i++) {
        for (int j = i + 1; j < 5; j++) {
            Node_add_neighbor(&nodes[i], &nodes[j]);
            Node_add_neighbor(&nodes[j], &nodes[i]);
        }
    }
    ConsensusMechanism mechanism;
    ConsensusMechanism_init(&mechanism, &network);
    ConsensusMechanism_simulate(&mechanism);
    return 0;
}