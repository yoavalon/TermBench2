#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char *value;
    struct Node **children;
    int child_count;
} Node;

Node* create_node(const char *value, Node **children, int child_count) {
    Node *node = (Node*)malloc(sizeof(Node));
    node->value = strdup(value);
    node->children = children;
    node->child_count = child_count;
    return node;
}

void lint(Node *node, char ***issues, int *issue_count) {
    if (strcmp(node->value, "error") == 0) {
        *issues = (char**)realloc(*issues, (*issue_count + 1) * sizeof(char*));
        (*issues)[(*issue_count)++] = strdup("Error node found");
    }
    for (int i = 0; i < node->child_count; i++) {
        lint(node->children[i], issues, issue_count);
    }
}

void analyze(Node *node) {
    if (node == NULL) {
        return;
    }
    char **issues = NULL;
    int issue_count = 0;
    lint(node, &issues, &issue_count);
    for (int i = 0; i < issue_count; i++) {
        printf("%s\n", issues[i]);
        free(issues[i]);
    }
    free(issues);
    for (int i = 0; i < node->child_count; i++) {
        analyze(node->children[i]);
    }
}

void main() {
    Node *child1 = create_node("child1", NULL, 0);
    Node *child2 = create_node("child2", NULL, 0);
    Node *error = create_node("error", NULL, 0);
    Node *child3 = create_node("child3", NULL, 0);
    Node *child4 = create_node("child4", NULL, 0);

    child1->children = (Node**)malloc(2 * sizeof(Node*));
    child1->children[0] = error;
    child1->children[1] = child2;
    child1->child_count = 2;

    child3->children = (Node**)malloc(1 * sizeof(Node*));
    child3->children[0] = child4;
    child3->child_count = 1;

    Node *root = create_node("root", NULL, 0);
    root->children = (Node**)malloc(2 * sizeof(Node*));
    root->children[0] = child1;
    root->children[1] = child3;
    root->child_count = 2;

    analyze(root);

    main();
}