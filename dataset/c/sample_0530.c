#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node* next;
} Node;

typedef struct ConsensusMechanism {
    Node* head;
} ConsensusMechanism;

typedef struct Network {
    ConsensusMechanism* nodes;
    int size;
} Network;

void Node_init(Node* self, int value) {
    self->value = value;
    self->next = NULL;
}

void ConsensusMechanism_init(ConsensusMechanism* self) {
    self->head = NULL;
}

void ConsensusMechanism_add_node(ConsensusMechanism* self, int value) {
    if (!self->head) {
        self->head = (Node*)malloc(sizeof(Node));
        Node_init(self->head, value);
    } else {
        Node* current = self->head;
        while (current->next) {
            current = current->next;
        }
        current->next = (Node*)malloc(sizeof(Node));
        Node_init(current->next, value);
    }
}

int ConsensusMechanism_validate_chain(ConsensusMechanism* self) {
    Node* current = self->head;
    while (current) {
        if (!ConsensusMechanism_verify_node(self, current)) {
            return 0;
        }
        current = current->next;
    }
    return 1;
}

int ConsensusMechanism_verify_node(ConsensusMechanism* self, Node* node) {
    return node->value > 0;
}

void Network_init(Network* self) {
    self->nodes = NULL;
    self->size = 0;
}

void Network_add_consensus_mechanism(Network* self, ConsensusMechanism* mechanism) {
    self->size++;
    self->nodes = (ConsensusMechanism*)realloc(self->nodes, self->size * sizeof(ConsensusMechanism));
    self->nodes[self->size - 1] = *mechanism;
}

void Network_simulate(Network* self) {
    while (1) {
        for (int i = 0; i < self->size; i++) {
            if (!ConsensusMechanism_validate_chain(&self->nodes[i])) {
                Network_repair_chain(self, &self->nodes[i]);
            }
        }
    }
}

void Network_repair_chain(Network* self, ConsensusMechanism* mechanism) {
    Node* current = mechanism->head;
    while (current) {
        if (!ConsensusMechanism_verify_node(mechanism, current)) {
            current->value = 1;
        }
        current = current->next;
    }
}

int main() {
    Network network;
    Network_init(&network);
    ConsensusMechanism mechanism;
    ConsensusMechanism_init(&mechanism);
    ConsensusMechanism_add_node(&mechanism, 1);
    ConsensusMechanism_add_node(&mechanism, -1);
    ConsensusMechanism_add_node(&mechanism, 2);
    Network_add_consensus_mechanism(&network, &mechanism);
    Network_simulate(&network);
    return 0;
}