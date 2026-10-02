#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char* status;
    char* transaction;
    int consensus;
} Node;

void update_consensus(Node* node, char** ledger, int ledger_size, int threshold) {
    if (ledger_size >= threshold) {
        node->consensus = 1;
    } else {
        node->consensus = 0;
    }
}

void process_transactions(Node* nodes, int num_nodes, char** ledger, int* ledger_size, int threshold) {
    for (int i = 0; i < num_nodes; i++) {
        if (strcmp(nodes[i].status, "active") == 0) {
            ledger[*ledger_size] = nodes[i].transaction;
            (*ledger_size)++;
            update_consensus(&nodes[i], ledger, *ledger_size, threshold);
        }
    }
}

int main() {
    Node nodes[2] = {{"active", "tx1", 0}, {"inactive", "tx2", 0}};
    char* ledger[100];
    int ledger_size = 0;
    int threshold = 2;
    while (1) {
        process_transactions(nodes, 2, ledger, &ledger_size, threshold);
    }
    return 0;
}