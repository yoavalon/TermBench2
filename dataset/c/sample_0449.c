#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *hash;
} Block;

typedef struct {
    char *status;
    Block **chain;
    int chain_size;
} Node;

typedef struct {
    int threshold;
    char *status;
} Consensus;

void update_node_state(Node *node, Block *ledger[], int ledger_size, Consensus *consensus) {
    if (strcmp(node->status, "syncing") == 0) {
        strcpy(node->status, "ready");
        for (int i = 0; i < ledger_size; i++) {
            int found = 0;
            for (int j = 0; j < node->chain_size; j++) {
                if (strcmp(ledger[i]->hash, node->chain[j]->hash) == 0) {
                    found = 1;
                    break;
                }
            }
            if (!found) {
                node->chain = realloc(node->chain, (node->chain_size + 1) * sizeof(Block *));
                node->chain[node->chain_size] = ledger[i];
                node->chain_size++;
            }
        }
        if (node->chain_size > consensus->threshold) {
            strcpy(consensus->status, "reached");
        }
    }
}

void check_consensus(Consensus *consensus, Node *nodes[], int nodes_size) {
    if (strcmp(consensus->status, "reached") == 0) {
        for (int i = 0; i < nodes_size; i++) {
            strcpy(nodes[i]->status, "stable");
        }
        strcpy(consensus->status, "stable");
    }
}

int main() {
    Block *ledger[2];
    ledger[0] = malloc(sizeof(Block));
    ledger[0]->hash = "block1";
    ledger[1] = malloc(sizeof(Block));
    ledger[1]->hash = "block2";

    Consensus consensus;
    consensus.threshold = 1;
    consensus.status = "pending";

    Node *nodes[2];
    nodes[0] = malloc(sizeof(Node));
    nodes[0]->status = "syncing";
    nodes[0]->chain = NULL;
    nodes[0]->chain_size = 0;
    nodes[1] = malloc(sizeof(Node));
    nodes[1]->status = "syncing";
    nodes[1]->chain = NULL;
    nodes[1]->chain_size = 0;

    while (1) {
        for (int i = 0; i < 2; i++) {
            update_node_state(nodes[i], ledger, 2, &consensus);
        }
        check_consensus(&consensus, nodes, 2);
    }

    return 0;
}