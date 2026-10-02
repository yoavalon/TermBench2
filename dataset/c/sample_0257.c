#include <stdio.h>
#include <stdlib.h>

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
    } else {
        Node* current = list->head;
        while (current->next) {
            current = current->next;
        }
        current->next = new_node;
    }
}

int LinkedList_get_length(LinkedList* list) {
    int count = 0;
    Node* current = list->head;
    while (current) {
        count++;
        current = current->next;
    }
    return count;
}

LinkedList* process_data(int* data, int length) {
    LinkedList* linked_list = (LinkedList*)malloc(sizeof(LinkedList));
    LinkedList_init(linked_list);
    for (int i = 0; i < length; i++) {
        LinkedList_append(linked_list, data[i]);
    }
    return linked_list;
}

char* analyze_boundaries(LinkedList* linked_list) {
    int length = LinkedList_get_length(linked_list);
    if (length < 10) {
        return "Under limit";
    } else if (length > 20) {
        return "Over limit";
    } else {
        return "Within limits";
    }
}

void main() {
    int data[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};
    LinkedList* processed_data = process_data(data, sizeof(data) / sizeof(data[0]));
    char* result = analyze_boundaries(processed_data);
    printf("%s\n", result);
}