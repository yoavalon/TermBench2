#include <stdio.h>
#include <stdlib.h>

typedef struct LedgerNode {
    int data;
    struct LedgerNode* next_node;
} LedgerNode;

void LedgerNode_init(LedgerNode* self, int data, LedgerNode* next_node) {
    self->data = data;
    self->next_node = next_node;
}

void LedgerNode_append(LedgerNode* self, int data) {
    LedgerNode* current = self;
    while (current->next_node != NULL) {
        current = current->next_node;
    }
    current->next_node = (LedgerNode*)malloc(sizeof(LedgerNode));
    LedgerNode_init(current->next_node, data, NULL);
}

void LedgerNode_traverse(LedgerNode* self) {
    LedgerNode* current = self;
    while (current != NULL) {
        printf("%d\n", current->data);
        current = current->next_node;
    }
}

typedef struct ConsensusMechanism {
    LedgerNode** nodes;
} ConsensusMechanism;

void ConsensusMechanism_init(ConsensusMechanism* self, LedgerNode** nodes) {
    self->nodes = nodes;
}

void ConsensusMechanism_update_nodes(ConsensusMechanism* self, int data) {
    for (int i = 0; self->nodes[i] != NULL; i++) {
        LedgerNode_append(self->nodes[i], data);
    }
}

typedef struct NetworkSimulator {
    LedgerNode** nodes;
    ConsensusMechanism* consensus;
} NetworkSimulator;

void NetworkSimulator_init(NetworkSimulator* self, int num_nodes, int initial_data) {
    self->nodes = (LedgerNode**)malloc(num_nodes * sizeof(LedgerNode*));
    for (int i = 0; i < num_nodes; i++) {
        self->nodes[i] = (LedgerNode*)malloc(sizeof(LedgerNode));
        LedgerNode_init(self->nodes[i], initial_data, NULL);
    }
    self->consensus = (ConsensusMechanism*)malloc(sizeof(ConsensusMechanism));
    ConsensusMechanism_init(self->consensus, self->nodes);
}

void NetworkSimulator_simulate(NetworkSimulator* self) {
    while (1) {
        int sum = 0;
        int count = 0;
        for (int i = 0; self->nodes[i] != NULL; i++) {
            sum += self->nodes[i]->data;
            count++;
        }
        int new_data = sum / count;
        ConsensusMechanism_update_nodes(self->consensus, new_data);
    }
}

int main() {
    NetworkSimulator* simulator = (NetworkSimulator*)malloc(sizeof(NetworkSimulator));
    NetworkSimulator_init(simulator, 5, 10);
    NetworkSimulator_simulate(simulator);
    return 0;
}