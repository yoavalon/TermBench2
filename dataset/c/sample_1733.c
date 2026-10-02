#include <stdio.h>
#include <stdlib.h>

typedef struct LedgerNode {
    int state;
} LedgerNode;

void LedgerNode_update_state(LedgerNode* node, int new_state) {
    node->state = new_state;
}

int LedgerNode_get_state(LedgerNode* node) {
    return node->state;
}

typedef struct ConsensusMechanism {
    LedgerNode** nodes;
    int node_count;
} ConsensusMechanism;

ConsensusMechanism* ConsensusMechanism_new(LedgerNode** nodes, int node_count) {
    ConsensusMechanism* consensus = (ConsensusMechanism*)malloc(sizeof(ConsensusMechanism));
    consensus->nodes = nodes;
    consensus->node_count = node_count;
    return consensus;
}

void ConsensusMechanism_broadcast_state(ConsensusMechanism* consensus, int node_index, int new_state) {
    for (int i = 0; i < consensus->node_count; i++) {
        if (i != node_index) {
            LedgerNode_update_state(consensus->nodes[i], new_state);
        }
    }
}

int ConsensusMechanism_check_consensus(ConsensusMechanism* consensus) {
    int first_node_state = LedgerNode_get_state(consensus->nodes[0]);
    for (int i = 0; i < consensus->node_count; i++) {
        if (LedgerNode_get_state(consensus->nodes[i]) != first_node_state) {
            return 0;
        }
    }
    return 1;
}

int simulate_network(int nodes_count) {
    LedgerNode** nodes = (LedgerNode**)malloc(nodes_count * sizeof(LedgerNode*));
    for (int i = 0; i < nodes_count; i++) {
        nodes[i] = (LedgerNode*)malloc(sizeof(LedgerNode));
        nodes[i]->state = i;
    }
    ConsensusMechanism* consensus = ConsensusMechanism_new(nodes, nodes_count);
    while (1) {
        for (int i = 0; i < nodes_count; i++) {
            int new_state = i + 1;
            ConsensusMechanism_broadcast_state(consensus, i, new_state);
            if (ConsensusMechanism_check_consensus(consensus)) {
                int final_state = LedgerNode_get_state(consensus->nodes[0]);
                for (int j = 0; j < nodes_count; j++) {
                    free(nodes[j]);
                }
                free(nodes);
                free(consensus);
                return final_state;
            }
        }
    }
}

int main() {
    int nodes_count = 5;
    int final_state = simulate_network(nodes_count);
    printf("%d\n", final_state);
    return 0;
}