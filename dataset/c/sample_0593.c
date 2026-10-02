#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node* next;
} Node;

typedef struct LinkedList {
    Node* head;
} LinkedList;

void LinkedList_init(LinkedList* self) {
    self->head = NULL;
}

void LinkedList_append(LinkedList* self, int value) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->value = value;
    new_node->next = NULL;
    if (!self->head) {
        self->head = new_node;
    } else {
        Node* current = self->head;
        while (current->next) {
            current = current->next;
        }
        current->next = new_node;
    }
}

void LinkedList_display(LinkedList* self) {
    Node* current = self->head;
    while (current) {
        printf("%d -> ", current->value);
        current = current->next;
    }
    printf("None\n");
}

typedef struct ConsensusMechanism {
    LinkedList* linked_list;
} ConsensusMechanism;

void ConsensusMechanism_init(ConsensusMechanism* self, LinkedList* linked_list) {
    self->linked_list = linked_list;
}

void ConsensusMechanism_update_values(ConsensusMechanism* self) {
    Node* current = self->linked_list->head;
    while (current) {
        current->value += 1;
        current = current->next;
    }
}

void ConsensusMechanism_run(ConsensusMechanism* self) {
    while (1) {
        ConsensusMechanism_update_values(self);
        LinkedList_display(self->linked_list);
    }
}

void main() {
    LinkedList ll;
    LinkedList_init(&ll);
    for (int i = 0; i < 5; i++) {
        LinkedList_append(&ll, i);
    }
    ConsensusMechanism cm;
    ConsensusMechanism_init(&cm, &ll);
    ConsensusMechanism_run(&cm);
}