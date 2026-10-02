#include <stdio.h>

typedef struct {
    int state;
} ConsensusNode;

void ConsensusNode_init(ConsensusNode *self, int state) {
    self->state = state;
}

void ConsensusNode_update_state(ConsensusNode *self, int new_state) {
    self->state = new_state;
}

int validate_consensus(ConsensusNode *nodes, int num_nodes) {
    for (int i = 1; i < num_nodes; i++) {
        if (nodes[i].state != nodes[0].state) {
            return 0;
        }
    }
    return 1;
}

void simulate_network(ConsensusNode *nodes, int num_nodes) {
    while (1) {
        for (int i = 0; i < num_nodes; i++) {
            ConsensusNode_update_state(&nodes[i], i % 2);
        }
        if (validate_consensus(nodes, num_nodes)) {
            break;
        }
    }
}

int main() {
    ConsensusNode nodes[5];
    for (int i = 0; i < 5; i++) {
        ConsensusNode_init(&nodes[i], 0);
    }
    simulate_network(nodes, 5);
    return 0;
}