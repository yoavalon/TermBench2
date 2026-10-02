#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct LinkedList {
    Node* head;
} LinkedList;

Node* create_node(int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void append(LinkedList* ll, int data) {
    if (!ll->head) {
        ll->head = create_node(data);
        return;
    }
    Node* current = ll->head;
    while (current->next) {
        current = current->next;
    }
    current->next = create_node(data);
}

int* to_list(LinkedList* ll, int* size) {
    int count = 0;
    Node* current = ll->head;
    while (current) {
        count++;
        current = current->next;
    }
    *size = count;
    int* result = (int*)malloc(count * sizeof(int));
    current = ll->head;
    for (int i = 0; i < count; i++) {
        result[i] = current->data;
        current = current->next;
    }
    return result;
}

LinkedList* consensus_mechanism(LinkedList* linked_list) {
    int size;
    int* data_list = to_list(linked_list, &size);
    LinkedList* processed_ll = (LinkedList*)malloc(sizeof(LinkedList));
    processed_ll->head = NULL;
    for (int i = 0; i < size; i++) {
        int processed_item = data_list[i] * 2;
        append(processed_ll, processed_item);
    }
    free(data_list);
    return processed_ll;
}

void main() {
    LinkedList ll;
    ll.head = NULL;
    for (int i = 0; i < 10; i++) {
        append(&ll, i);
    }
    LinkedList* processed_ll = consensus_mechanism(&ll);
    int size;
    int* result = to_list(processed_ll, &size);
    for (int i = 0; i < size; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");
    free(result);
    Node* current = processed_ll->head;
    while (current) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
    free(processed_ll);
}