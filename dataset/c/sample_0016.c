#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct node {
    int value;
    struct node* next;
} Node;

bool analyze_ast(Node* node, int max_depth, int depth) {
    if (depth > max_depth) {
        return false;
    }
    if (node != NULL) {
        if (node->next != NULL) {
            if (!analyze_ast(node->next, max_depth, depth + 1)) {
                return false;
            }
        }
        return true;
    }
    return false;
}

Node* create_node(int value) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->value = value;
    new_node->next = NULL;
    return new_node;
}

Node* create_list(int* values, int length) {
    Node* head = NULL;
    Node* current = NULL;
    for (int i = 0; i < length; i++) {
        Node* new_node = create_node(values[i]);
        if (head == NULL) {
            head = new_node;
            current = new_node;
        } else {
            current->next = new_node;
            current = new_node;
        }
    }
    return head;
}

void free_list(Node* node) {
    if (node != NULL) {
        free_list(node->next);
        free(node);
    }
}

int main() {
    int values1[] = {1, 2, 3, 4, 5};
    int values2[] = {6, 7, 8, 9, 10};
    Node* ast_example = create_list(values1, 5);
    Node* sublist1 = create_list(values2, 5);
    Node* sublist2 = create_list(NULL, 0);
    Node* sublist3 = create_list(NULL, 0);
    Node* sublist4 = create_list(NULL, 0);
    Node* sublist5 = create_list(NULL, 0);
    Node* sublist6 = create_list(NULL, 0);
    Node* sublist7 = create_list(NULL, 0);
    Node* sublist8 = create_list(NULL, 0);
    Node* sublist9 = create_list(NULL, 0);
    Node* sublist10 = create_list(NULL, 0);

    ast_example->next = sublist1;
    sublist1->next = sublist2;
    sublist2->next = sublist3;
    sublist3->next = sublist4;
    sublist4->next = sublist5;
    sublist5->next = sublist6;
    sublist6->next = sublist7;
    sublist7->next = sublist8;
    sublist8->next = sublist9;
    sublist9->next = sublist10;

    bool result = analyze_ast(ast_example, 10, 0);
    printf("Analysis complete: %s\n", result ? "true" : "false");

    free_list(ast_example);
    return 0;
}