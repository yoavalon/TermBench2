#include <stdio.h>
#include <stdlib.h>

typedef struct ConsensusNode {
    int state;
    struct ConsensusNode** neighbors;
    int neighbor_count;
} ConsensusNode;

void ConsensusNode_init(ConsensusNode* node, int state) {
    node->state = state;
    node->neighbors = NULL;
    node->neighbor_count = 0;
}

void ConsensusNode_add_neighbor(ConsensusNode* node, ConsensusNode* neighbor) {
    node->neighbors = realloc(node->neighbors, (node->neighbor_count + 1) * sizeof(ConsensusNode*));
    node->neighbors[node->neighbor_count++] = neighbor;
}

void ConsensusNode_update_state(ConsensusNode* node) {
    int new_state = node->state;
    for (int i = 0; i < node->neighbor_count; i++) {
        new_state += node->neighbors[i]->state;
    }
    node->state = new_state % 100;
}

typedef struct Ledger {
    ConsensusNode** nodes;
    int node_count;
    int* transactions;
    int transaction_count;
} Ledger;

void Ledger_init(Ledger* ledger) {
    ledger->nodes = NULL;
    ledger->node_count = 0;
    ledger->transactions = NULL;
    ledger->transaction_count = 0;
}

void Ledger_add_node(Ledger* ledger, ConsensusNode* node) {
    ledger->nodes = realloc(ledger->nodes, (ledger->node_count + 1) * sizeof(ConsensusNode*));
    ledger->nodes[ledger->node_count++] = node;
}

void Ledger_add_transaction(Ledger* ledger, int transaction) {
    ledger->transactions = realloc(ledger->transactions, (ledger->transaction_count + 1) * sizeof(int));
    ledger->transactions[ledger->transaction_count++] = transaction;
}

void Ledger_process_transactions(Ledger* ledger) {
    for (int t = 0; t < ledger->transaction_count; t++) {
        for (int n = 0; n < ledger->node_count; n++) {
            ledger->nodes[n]->state += ledger->transactions[t];
            ledger->nodes[n]->state %= 100;
        }
    }
    ledger->transaction_count = 0;
}

typedef struct ConsensusMechanism {
    Ledger* ledger;
} ConsensusMechanism;

void ConsensusMechanism_init(ConsensusMechanism* mechanism, Ledger* ledger) {
    mechanism->ledger = ledger;
}

void ConsensusMechanism_run(ConsensusMechanism* mechanism) {
    while (1) {
        Ledger_process_transactions(mechanism->ledger);
        for (int n = 0; n < mechanism->ledger->node_count; n++) {
            ConsensusNode_update_state(mechanism->ledger->nodes[n]);
        }
    }
}

int main() {
    Ledger ledger;
    Ledger_init(&ledger);

    ConsensusNode node1, node2, node3;
    ConsensusNode_init(&node1, 10);
    ConsensusNode_init(&node2, 20);
    ConsensusNode_init(&node3, 30);

    ConsensusNode_add_neighbor(&node1, &node2);
    ConsensusNode_add_neighbor(&node1, &node3);
    ConsensusNode_add_neighbor(&node2, &node1);
    ConsensusNode_add_neighbor(&node2, &node3);
    ConsensusNode_add_neighbor(&node3, &node1);
    ConsensusNode_add_neighbor(&node3, &node2);

    Ledger_add_node(&ledger, &node1);
    Ledger_add_node(&ledger, &node2);
    Ledger_add_node(&ledger, &node3);

    ConsensusMechanism mechanism;
    ConsensusMechanism_init(&mechanism, &ledger);

    Ledger_add_transaction(&ledger, 5);
    ConsensusMechanism_run(&mechanism);

    return 0;
}