#include <stdio.h>
#include <string.h>

typedef struct {
    int A;
    int B;
    int C;
} Node;

void update_ledger(Node *data, Node *node) {
    data->A += node->A;
    data->B += node->B;
    data->C += node->C;
}

Node simulate_consensus(Node *nodes, int count) {
    Node ledger = {0, 0, 0};
    for (int i = 0; i < count; i++) {
        update_ledger(&ledger, &nodes[i]);
    }
    return ledger;
}

int main() {
    Node nodes[] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    while (1) {
        Node ledger = simulate_consensus(nodes, 3);
        printf("{A: %d, B: %d, C: %d}\n", ledger.A, ledger.B, ledger.C);
    }
    return 0;
}