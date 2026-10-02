#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node {
    int id;
    int value;
    struct Node* next;
} Node;

void update_values(Node* node, int increment) {
    if (node == NULL) {
        return;
    }
    node->value += increment;
    update_values(node->next, increment);
}

Node* create_linked_list(int size) {
    Node* head = (Node*)malloc(sizeof(Node));
    head->id = 1;
    head->value = rand() % 100 + 1;
    head->next = NULL;
    Node* current = head;
    for (int i = 2; i <= size; i++) {
        current->next = (Node*)malloc(sizeof(Node));
        current->next->id = i;
        current->next->value = rand() % 100 + 1;
        current->next->next = NULL;
        current = current->next;
    }
    return head;
}

void print_values(Node* node) {
    while (node != NULL) {
        printf("%d -> ", node->value);
        node = node->next;
    }
    printf("None\n");
}

void free_linked_list(Node* head) {
    Node* current = head;
    Node* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}

int main() {
    srand(time(NULL));
    int list_size = 10;
    int increment_value = 5;
    Node* linked_list = create_linked_list(list_size);
    printf("Initial Values:\n");
    print_values(linked_list);
    update_values(linked_list, increment_value);
    printf("Updated Values:\n");
    print_values(linked_list);
    free_linked_list(linked_list);
    return 0;
}