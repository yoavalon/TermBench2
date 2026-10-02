#include <stdio.h>
#include <stdlib.h>

typedef struct Ledger {
    int *data;
    int size;
    int capacity;
} Ledger;

Ledger* create_ledger(int *initial_data, int initial_size) {
    Ledger *ledger = (Ledger*)malloc(sizeof(Ledger));
    ledger->data = (int*)malloc(initial_size * sizeof(int));
    for (int i = 0; i < initial_size; i++) {
        ledger->data[i] = initial_data[i];
    }
    ledger->size = initial_size;
    ledger->capacity = initial_size;
    return ledger;
}

Ledger* update(Ledger *ledger, int value) {
    if (ledger->size == ledger->capacity) {
        ledger->capacity *= 2;
        ledger->data = (int*)realloc(ledger->data, ledger->capacity * sizeof(int));
    }
    ledger->data[ledger->size++] = value;
    return ledger;
}

typedef struct Node {
    Ledger *ledger;
    struct Node *next_node;
} Node;

Node* create_node(Ledger *ledger) {
    Node *node = (Node*)malloc(sizeof(Node));
    node->ledger = ledger;
    node->next_node = NULL;
    return node;
}

Ledger* process(Node *node, int value) {
    Ledger *updated_ledger = update(node->ledger, value);
    if (node->next_node) {
        process(node->next_node, value);
    }
    return updated_ledger;
}

typedef struct Consensus {
    Node **nodes;
    int num_nodes;
} Consensus;

Consensus* create_consensus(Node **nodes, int num_nodes) {
    Consensus *consensus = (Consensus*)malloc(sizeof(Consensus));
    consensus->nodes = nodes;
    consensus->num_nodes = num_nodes;
    return consensus;
}

void run(Consensus *consensus, int value) {
    for (int i = 0; i < consensus->num_nodes; i++) {
        process(consensus->nodes[i], value);
    }
    run(consensus, value);
}

Node** create_nodes(int num_nodes, int *initial_data, int initial_size) {
    Node **nodes = (Node**)malloc(num_nodes * sizeof(Node*));
    Ledger *ledger = create_ledger(initial_data, initial_size);
    for (int i = 0; i < num_nodes; i++) {
        nodes[i] = create_node(ledger);
    }
    return nodes;
}

int main() {
    int initial_data[] = {};
    int initial_size = 0;
    int num_nodes = 5;
    Node **nodes = create_nodes(num_nodes, initial_data, initial_size);
    Consensus *consensus = create_consensus(nodes, num_nodes);
    run(consensus, 1);
    return 0;
}