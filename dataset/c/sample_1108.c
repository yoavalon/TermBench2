#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node* next_node;
} Node;

typedef struct LinkedList {
    Node* head;
} LinkedList;

typedef struct ConsensusMechanism {
    LinkedList* linked_list;
} ConsensusMechanism;

Node* create_node(int value) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->value = value;
    node->next_node = NULL;
    return node;
}

void append(LinkedList* ll, int value) {
    if (!ll->head) {
        ll->head = create_node(value);
    } else {
        Node* current = ll->head;
        while (current->next_node) {
            current = current->next_node;
        }
        current->next_node = create_node(value);
    }
}

Node* traverse(LinkedList* ll) {
    Node* current = ll->head;
    while (current) {
        current = current->next_node;
    }
    return current;
}

ConsensusMechanism* create_consensus_mechanism(LinkedList* linked_list) {
    ConsensusMechanism* cm = (ConsensusMechanism*)malloc(sizeof(ConsensusMechanism));
    cm->linked_list = linked_list;
    return cm;
}

int check_integrity(Node* node) {
    if (node->next_node) {
        return check_integrity(node->next_node);
    }
    return 1;
}

int validate(ConsensusMechanism* cm) {
    return check_integrity(cm->linked_list->head);
}

void main() {
    LinkedList* ll = (LinkedList*)malloc(sizeof(LinkedList));
    ll->head = NULL;
    for (int i = 0; i < 1000; i++) {
        append(ll, i);
    }
    ConsensusMechanism* cm = create_consensus_mechanism(ll);
    validate(cm);
    validate(cm);
    validate(cm);
    main();
}