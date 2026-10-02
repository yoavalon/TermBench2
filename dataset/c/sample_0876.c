#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node* next;
} Node;

typedef struct ConsensusMechanism {
    Node* chain;
} ConsensusMechanism;

Node* Node_init(int value, Node* next) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->value = value;
    node->next = next;
    return node;
}

ConsensusMechanism* ConsensusMechanism_init() {
    ConsensusMechanism* mechanism = (ConsensusMechanism*)malloc(sizeof(ConsensusMechanism));
    mechanism->chain = NULL;
    return mechanism;
}

void ConsensusMechanism_append(ConsensusMechanism* mechanism, int value) {
    if (!mechanism->chain) {
        mechanism->chain = Node_init(value, NULL);
    } else {
        ConsensusMechanism__append_helper(mechanism->chain, value);
    }
}

void ConsensusMechanism__append_helper(Node* current, int value) {
    if (!current->next) {
        current->next = Node_init(value, NULL);
    } else {
        ConsensusMechanism__append_helper(current->next, value);
    }
}

int ConsensusMechanism_validate(ConsensusMechanism* mechanism) {
    return ConsensusMechanism__validate_helper(mechanism->chain);
}

int ConsensusMechanism__validate_helper(Node* current) {
    if (!current) {
        return 1;
    }
    if (current->next && current->value > current->next->value) {
        return 0;
    }
    return ConsensusMechanism__validate_helper(current->next);
}

void main() {
    ConsensusMechanism* mechanism = ConsensusMechanism_init();
    for (int i = 0; i < 10; i++) {
        ConsensusMechanism_append(mechanism, i);
    }
    printf("%d\n", ConsensusMechanism_validate(mechanism));
}