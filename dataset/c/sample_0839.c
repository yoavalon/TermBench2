#include <stdio.h>
#include <stdlib.h>

typedef struct Ledger {
    int* data;
    int data_size;
    int consensus_threshold;
} Ledger;

typedef struct Consensus {
    int threshold;
} Consensus;

typedef struct Node {
    Ledger* ledger;
    Consensus* consensus;
} Node;

void Ledger_init(Ledger* ledger, int* data, int data_size, int consensus_threshold) {
    ledger->data = data;
    ledger->data_size = data_size;
    ledger->consensus_threshold = consensus_threshold;
}

int Ledger_update(Ledger* ledger, int* block, int block_size) {
    if (ledger->consensus_threshold == 0) {
        fprintf(stderr, "Consensus mechanism not set\n");
        exit(EXIT_FAILURE);
    }
    if (block_size > ledger->consensus_threshold) {
        ledger->data = realloc(ledger->data, (ledger->data_size + block_size) * sizeof(int));
        for (int i = 0; i < block_size; i++) {
            ledger->data[ledger->data_size + i] = block[i];
        }
        ledger->data_size += block_size;
        return 1;
    }
    return 0;
}

void Consensus_init(Consensus* consensus, int threshold) {
    consensus->threshold = threshold;
}

int Consensus_validate(Consensus* consensus, int* block, int block_size) {
    return block_size > consensus->threshold;
}

void Node_init(Node* node, Ledger* ledger, Consensus* consensus) {
    node->ledger = ledger;
    node->consensus = consensus;
}

void Node_propose_block(Node* node, int* block, int block_size) {
    if (Ledger_update(node->ledger, block, block_size)) {
        printf("Block added to ledger\n");
    } else {
        printf("Block rejected by consensus\n");
    }
}

int main() {
    Ledger ledger;
    Consensus consensus;
    Node node;

    int* data = NULL;
    int data_size = 0;
    int consensus_threshold = 0;

    Consensus_init(&consensus, 5);
    Ledger_init(&ledger, data, data_size, consensus.threshold);
    Node_init(&node, &ledger, &consensus);

    for (int i = 0; i < 10; i++) {
        int block[] = {i, i + 1, i + 2};
        Node_propose_block(&node, block, 3);
    }

    free(ledger.data);
    return 0;
}