#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    double value;
} Node;

double calculate_consensus(Node node, double value) {
    double precision = 0.0001;
    double delta = 1.0;
    while (delta > precision) {
        double proposed_value = (value + node.value) / 2;
        delta = fabs(proposed_value - value);
        value = proposed_value;
    }
    return value;
}

double update_ledger(Node *nodes, int num_nodes, double initial_value) {
    double consensus_value = initial_value;
    for (int i = 0; i < num_nodes; i++) {
        consensus_value = calculate_consensus(nodes[i], consensus_value);
    }
    return consensus_value;
}

int main() {
    Node nodes[] = {{1.5}, {2.5}, {3.5}};
    int num_nodes = sizeof(nodes) / sizeof(nodes[0]);
    double initial_value = 2.0;

    while (1) {
        double final_value = update_ledger(nodes, num_nodes, initial_value);
        printf("Consensus Value: %f\n", final_value);
    }

    return 0;
}