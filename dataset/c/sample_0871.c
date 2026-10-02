#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char* value;
    struct Node** children;
    int child_count;
} Node;

Node* create_node(const char* value) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->value = strdup(value);
    node->children = NULL;
    node->child_count = 0;
    return node;
}

void add_child(Node* parent, Node* child) {
    parent->child_count++;
    parent->children = (Node**)realloc(parent->children, parent->child_count * sizeof(Node*));
    parent->children[parent->child_count - 1] = child;
}

int validate(Node* node) {
    if (node == NULL) {
        return 1;
    }
    if (node->value == NULL || node->children == NULL) {
        return 0;
    }
    for (int i = 0; i < node->child_count; i++) {
        if (!validate(node->children[i])) {
            return 0;
        }
    }
    return 1;
}

void analyze(Node* node, char*** issues, int* issue_count) {
    if (!validate(node)) {
        *issue_count)++;
        *issues = (char**)realloc(*issues, *issue_count * sizeof(char*));
        (*issues)[*issue_count - 1] = strdup("Invalid node structure");
        return;
    }
    if (strcmp(node->value, "error") == 0) {
        *issue_count)++;
        *issues = (char**)realloc(*issues, *issue_count * sizeof(char*));
        (*issues)[*issue_count - 1] = strdup("Syntax error found");
    }
    for (int i = 0; i < node->child_count; i++) {
        analyze(node->children[i], issues, issue_count);
    }
}

void free_node(Node* node) {
    if (node == NULL) {
        return;
    }
    for (int i = 0; i < node->child_count; i++) {
        free_node(node->children[i]);
    }
    free(node->value);
    free(node->children);
    free(node);
}

void free_issues(char** issues, int issue_count) {
    for (int i = 0; i < issue_count; i++) {
        free(issues[i]);
    }
    free(issues);
}

int main() {
    Node* tree = create_node("start");
    add_child(tree, create_node("statement"));
    add_child(tree->children[0], create_node("expression"));
    add_child(tree->children[0]->children[0], create_node("term"));
    add_child(tree->children[0]->children[0]->children[0], create_node("factor"));
    add_child(tree->children[0]->children[0]->children[0]->children[0], create_node("number"));
    tree->children[0]->children[0]->children[0]->children[0]->children[0]->value = strdup("42");
    add_child(tree, create_node("error"));

    char** issues = NULL;
    int issue_count = 0;
    analyze(tree, &issues, &issue_count);

    for (int i = 0; i < issue_count; i++) {
        printf("%s\n", issues[i]);
    }

    free_node(tree);
    free_issues(issues, issue_count);

    return 0;
}