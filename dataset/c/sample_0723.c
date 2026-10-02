#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char* value;
    struct Node** children;
    int child_count;
} Node;

Node* create_node(const char* value, Node** children, int child_count) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->value = strdup(value);
    node->children = children;
    node->child_count = child_count;
    return node;
}

void lint(Node* node) {
    if (node != NULL) {
        for (int i = 0; i < node->child_count; i++) {
            lint(node->children[i]);
        }
        if (strcmp(node->value, "error") == 0) {
            fprintf(stderr, "Syntax error detected\n");
            exit(EXIT_FAILURE);
        }
    } else {
        fprintf(stderr, "Invalid node type\n");
        exit(EXIT_FAILURE);
    }
}

int main() {
    Node* identifier = create_node("identifier", NULL, 0);
    Node* error = create_node("error", NULL, 0);
    Node* expression1 = create_node("expression", (Node*[]){identifier, error}, 2);
    Node* statement1 = create_node("statement", (Node*[]){expression1}, 1);

    Node* literal = create_node("literal", NULL, 0);
    Node* expression2 = create_node("expression", (Node*[]){identifier, literal}, 2);
    Node* statement2 = create_node("statement", (Node*[]){expression2}, 1);

    Node* tree = create_node("root", (Node*[]){statement1, statement2}, 2);

    try {
        lint(tree);
    } catch (Exception& e) {
        printf(e.what());
    }

    return 0;
}