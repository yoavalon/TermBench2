#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int id;
    struct Network *network;
    char state[10];
    int blockchain_size;
    struct Block *blockchain;
} ConsensusNode;

typedef struct Block {
    char data[20];
    int node_id;
} Block;

typedef struct Network {
    int node_count;
    struct Node *nodes;
} Network;

typedef struct {
    struct Network *network;
} ConsensusMechanism;

void propose_block(ConsensusNode *self, char *data) {
    strcpy(self->state, "proposing");
    Block block = {{0}, self->id};
    strcpy(block.data, data);
    for (int i = 0; i < self->network->node_count; i++) {
        if (self->network->nodes[i].id != self->id) {
            self->network->nodes[i].receive_message(&block);
        }
    }
}

void broadcast(ConsensusNode *self, Block *message) {
    for (int i = 0; i < self->network->node_count; i++) {
        if (self->network->nodes[i].id != self->id) {
            self->network->nodes[i].receive_message(message);
        }
    }
}

void receive_message(ConsensusNode *self, Block *message) {
    if (message->data[0] != '\0') {
        strcpy(self->state, "receiving");
        self->validate_block(message);
    } else {
        strcpy(self->state, "voting");
        self->handle_vote(message);
    }
}

void validate_block(ConsensusNode *self, Block *block) {
    if (self->is_valid_block(block)) {
        Block vote_message = {{0}, block->node_id};
        strcpy(vote_message.data, "approved");
        vote_message.node_id = block->node_id;
        broadcast(self, &vote_message);
    } else {
        Block vote_message = {{0}, block->node_id};
        strcpy(vote_message.data, "rejected");
        vote_message.node_id = block->node_id;
        broadcast(self, &vote_message);
    }
}

void handle_vote(ConsensusNode *self, Block *vote) {
    if (strcmp(vote->data, "approved") == 0) {
        self->add_block_to_chain(vote);
    }
}

int is_valid_block(ConsensusNode *self, Block *block) {
    return 1;
}

void add_block_to_chain(ConsensusNode *self, Block *block) {
    self->blockchain[self->blockchain_size++] = *block;
    strcpy(self->state, "idle");
}

void add_node(Network *self, ConsensusNode *node) {
    self->nodes[self->node_count++] = *node;
}

void broadcast_network(Network *self, Block *message) {
    for (int i = 0; i < self->node_count; i++) {
        self->nodes[i].receive_message(message);
    }
}

void run(ConsensusMechanism *self) {
    while (1) {
        for (int i = 0; i < self->network->node_count; i++) {
            if (strcmp(self->network->nodes[i].state, "idle") == 0) {
                propose_block(&self->network->nodes[i], "new_data");
            }
        }
    }
}

int main() {
    Network network = {0};
    network.nodes = malloc(5 * sizeof(ConsensusNode));
    for (int i = 0; i < 5; i++) {
        ConsensusNode node = {i, &network};
        node.blockchain = malloc(100 * sizeof(Block));
        add_node(&network, &node);
    }
    ConsensusMechanism consensus_mechanism = {&network};
    run(&consensus_mechanism);
    return 0;
}