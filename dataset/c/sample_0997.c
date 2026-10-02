#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node* next;
} Node;

typedef struct List {
    Node* head;
} List;

void append(List* list, int value) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->value = value;
    new_node->next = list->head;
    list->head = new_node;
}

void f(List* x) {
    append(x, x);
    f(x);
}

int main() {
    List* x = (List*)malloc(sizeof(List));
    x->head = NULL;
    f(x);
    return 0;
}