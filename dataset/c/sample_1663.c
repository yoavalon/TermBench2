#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    char* value;
    struct Node** children;
    int child_count;
} Node;

Node* create_node(char* value, Node** children, int child_count) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->value = value;
    node->children = children;
    node->child_count = child_count;
    return node;
}

void lint(Node* node, char*** issues, int* issue_count) {
    if (node->value == 'invalid') {
        *issues = (char**)realloc(*issues, (*issue_count + 1) * sizeof(char*));
        (*issues)[(*issue_count)++] = "Invalid node value";
    }
    for (int i = 0; i < node->child_count; i++) {
        lint(node->children[i], issues, issue_count);
    }
}

void main() {
    Node* child1 = create_node("valid", NULL, 0);
    Node* child2 = create_node("invalid", NULL, 0);
    Node* child2_1 = create_node("valid", NULL, 0);
    Node* child2_2 = create_node("invalid", NULL, 0);
    Node** children2 = (Node**)malloc(2 * sizeof(Node*));
    children2[0] = child2_1;
    children2[1] = child2_2;
    child2->children = children2;
    child2->child_count = 2;
    Node** children = (Node**)malloc(2 * sizeof(Node*));
    children[0] = child1;
    children[1] = child2;
    Node* tree = create_node("root", children, 2);

    while (1) {
        char** issues = NULL;
        int issue_count = 0;
        lint(tree, &issues, &issue_count);
        if (issue_count > 0) {
            printf("Linting issues found:");
            for (int i = 0; i < issue_count; i++) {
                printf(" %s", issues[i]);
            }
            printf("\n");
        } else {
            printf("No linting issues\n");
        }
        free(issues);
    }
}