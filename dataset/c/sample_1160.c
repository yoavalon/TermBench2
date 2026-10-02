#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct LinkedList {
    Node* head;
} LinkedList;

void Node_init(Node* node, int data) {
    node->data = data;
    node->next = NULL;
}

void LinkedList_init(LinkedList* ll) {
    ll->head = NULL;
}

void LinkedList_append(LinkedList* ll, int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    Node_init(new_node, data);
    if (ll->head == NULL) {
        ll->head = new_node;
        return;
    }
    Node* last = ll->head;
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = new_node;
}

void LinkedList_remove(LinkedList* ll, int key) {
    Node* temp = ll->head;
    if (temp != NULL && temp->data == key) {
        ll->head = temp->next;
        free(temp);
        return;
    }
    Node* prev = NULL;
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        return;
    }
    prev->next = temp->next;
    free(temp);
}

void recursive_consensus(Node* node, int value) {
    if (node == NULL) {
        return;
    }
    if (node->data == value) {
        node->data = value;
    }
    recursive_consensus(node->next, value);
}

void main() {
    LinkedList ll;
    LinkedList_init(&ll);
    for (int i = 0; i < 100; i++) {
        LinkedList_append(&ll, i);
    }
    recursive_consensus(ll.head, 50);
    main();
}