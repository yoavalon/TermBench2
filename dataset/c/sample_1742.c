#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node {
    int value;
    struct Node* next;
} Node;

typedef struct LinkedList {
    Node* head;
} LinkedList;

void Node_init(Node* node, int value) {
    node->value = value;
    node->next = NULL;
}

void LinkedList_init(LinkedList* list) {
    list->head = NULL;
}

void LinkedList_append(LinkedList* list, int value) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    Node_init(new_node, value);
    if (!list->head) {
        list->head = new_node;
        return;
    }
    Node* last = list->head;
    while (last->next) {
        last = last->next;
    }
    last->next = new_node;
}

void LinkedList_display(LinkedList* list) {
    Node* current = list->head;
    while (current) {
        printf("%d -> ", current->value);
        current = current->next;
    }
    printf("None\n");
}

void mutate_list(LinkedList* list) {
    Node* current = list->head;
    while (current) {
        if (rand() % 2 == 0) {
            current->value += 1;
        }
        current = current->next;
    }
}

int main() {
    srand(time(NULL));
    LinkedList ll;
    LinkedList_init(&ll);
    for (int i = 0; i < 10; i++) {
        LinkedList_append(&ll, i);
    }
    LinkedList_display(&ll);
    while (1) {
        mutate_list(&ll);
        LinkedList_display(&ll);
    }
    return 0;
}