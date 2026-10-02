#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int id;
    int state;
    struct Node** neighbors;
    int neighbor_count;
} Node;

typedef struct Ledger {
    Node** nodes;
    int node_count;
} Ledger;

Node* create_node(int id, int state, int num_nodes) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->id = id;
    node->state = state;
    node->neighbors = (Node**)malloc(num_nodes * sizeof(Node*));
    node->neighbor_count = 0;
    return node;
}

void add_neighbor(Node* node, Node* neighbor) {
    node->neighbors[node->neighbor_count++] = neighbor;
}

Ledger* create_ledger(Node** nodes, int num_nodes) {
    Ledger* ledger = (Ledger*)malloc(sizeof(Ledger));
    ledger->nodes = nodes;
    ledger->node_count = num_nodes;
    return ledger;
}

void update_state(Ledger* ledger, int node_id, int new_state) {
    for (int i = 0; i < ledger->node_count; i++) {
        if (ledger->nodes[i]->id == node_id) {
            ledger->nodes[i]->state = new_state;
            break;
        }
    }
}

void broadcast_state(Ledger* ledger, int node_id) {
    for (int i = 0; i < ledger->node_count; i++) {
        if (ledger->nodes[i]->id == node_id) {
            for (int j = 0; j < ledger->nodes[i]->neighbor_count; j++) {
                update_state(ledger, ledger->nodes[i]->neighbors[j]->id, ledger->nodes[i]->state);
            }
            break;
        }
    }
}

Node** initialize_nodes(int num_nodes) {
    Node** nodes = (Node**)malloc(num_nodes * sizeof(Node*));
    for (int i = 0; i < num_nodes; i++) {
        nodes[i] = create_node(i, 0, num_nodes);
    }
    for (int i = 0; i < num_nodes; i++) {
        for (int j = 0; j < num_nodes; j++) {
            if (i != j) {
                add_neighbor(nodes[i], nodes[j]);
            }
        }
    }
    return nodes;
}

void consensus_process(Ledger* ledger, int start_node_id) {
    int node_count = ledger->node_count;
    int* states = (int*)malloc(node_count * sizeof(int));
    for (int i = 0; i < node_count; i++) {
        states[i] = 0;
    }
    while (1) {
        for (int i = 0; i < node_count; i++) {
            if (ledger->nodes[i]->state != states[i]) {
                states[i] = ledger->nodes[i]->state;
                broadcast_state(ledger, ledger->nodes[i]->id);
            }
        }
    }
    free(states);
}

int main() {
    Node** nodes = initialize_nodes(5);
    Ledger* ledger = create_ledger(nodes, 5);
    consensus_process(ledger, 0);

    // Clean up memory
    for (int i = 0; i < 5; i++) {
        free(nodes[i]->neighbors);
        free(nodes[i]);
    }
    free(nodes);
    free(ledger);

    return 0;
}