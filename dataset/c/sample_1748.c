#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Block {
    char *data;
    int prev_hash;
    int hash;
} Block;

typedef struct ConsensusNode {
    int id;
    Block **chain;
    int chain_length;
} ConsensusNode;

typedef struct Network {
    ConsensusNode **nodes;
    int num_nodes;
} Network;

Network network;

int calculate_hash(const char *data, int prev_hash) {
    return hash((const void *)data, strlen(data), prev_hash);
}

Block* create_block(const char *data, int prev_hash) {
    Block *block = (Block *)malloc(sizeof(Block));
    block->data = strdup(data);
    block->prev_hash = prev_hash;
    block->hash = calculate_hash(data, prev_hash);
    return block;
}

void broadcast_block(ConsensusNode *self, Block *block) {
    for (int i = 0; i < network.num_nodes; i++) {
        if (network.nodes[i] != self) {
            network.nodes[i]->receive_block(block);
        }
    }
}

void receive_block(ConsensusNode *self, Block *block) {
    self->chain = (Block **)realloc(self->chain, (self->chain_length + 1) * sizeof(Block *));
    self->chain[self->chain_length++] = block;
}

ConsensusNode* create_consensus_node(int id) {
    ConsensusNode *node = (ConsensusNode *)malloc(sizeof(ConsensusNode));
    node->id = id;
    node->chain = NULL;
    node->chain_length = 0;
    return node;
}

Network* initialize_network(int num_nodes) {
    Network *net = (Network *)malloc(sizeof(Network));
    net->nodes = (ConsensusNode **)malloc(num_nodes * sizeof(ConsensusNode *));
    for (int i = 0; i < num_nodes; i++) {
        net->nodes[i] = create_consensus_node(i);
    }
    net->num_nodes = num_nodes;
    return net;
}

Block* generate_block(ConsensusNode *node, const char *data) {
    if (node->chain_length > 0) {
        Block *prev_block = node->chain[node->chain_length - 1];
        return create_block(data, prev_block->hash);
    } else {
        return create_block(data, 0);
    }
}

void simulate_consensus() {
    network = *initialize_network(5);
    Block *initial_block = generate_block(network.nodes[0], "Genesis");
    network.nodes[0]->add_block(initial_block);
    while (1) {
        for (int i = 0; i < network.num_nodes; i++) {
            char new_data[20];
            sprintf(new_data, "Transaction %d", network.nodes[i]->chain_length);
            Block *new_block = generate_block(network.nodes[i], new_data);
            network.nodes[i]->add_block(new_block);
        }
    }
}

int main() {
    simulate_consensus();
    return 0;
}