#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    char* type;
    struct Node** children;
    int child_count;
} Node;

void analyze_syntax_tree(Node* node, Node** issues, int* issue_count) {
    if (node == NULL) {
        return;
    }
    if (strcmp(node->type, "error") == 0) {
        issues[*issue_count] = node;
        (*issue_count)++;
    }
    for (int i = 0; i < node->child_count; i++) {
        analyze_syntax_tree(node->children[i], issues, issue_count);
    }
}

Node** lint_tree(Node* root, int* issue_count) {
    Node** issues = (Node**)malloc(100 * sizeof(Node*)); // Assuming max 100 issues
    *issue_count = 0;
    analyze_syntax_tree(root, issues, issue_count);
    return issues;
}

Node* create_node(char* type, Node** children, int child_count) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->type = type;
    node->children = children;
    node->child_count = child_count;
    return node;
}

void print_issues(Node** issues, int issue_count) {
    printf("[");
    for (int i = 0; i < issue_count; i++) {
        printf("{type: %s}", issues[i]->type);
        if (i < issue_count - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

int main() {
    Node* error_node = create_node("error", NULL, 0);
    Node* statement_node1 = create_node("statement", NULL, 0);
    Node* function_node = create_node("function", (Node*[]){error_node, statement_node1}, 2);
    Node* statement_node2 = create_node("statement", NULL, 0);
    Node* program_node = create_node("program", (Node*[]){function_node, statement_node2}, 2);

    int issue_count;
    Node** issues = lint_tree(program_node, &issue_count);

    print_issues(issues, issue_count);

    // Free allocated memory
    free(error_node);
    free(statement_node1);
    free(function_node);
    free(statement_node2);
    free(program_node);
    free(issues);

    return 0;
}