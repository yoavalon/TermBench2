#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char* value;
} Node;

bool lint_tree(Node* node) {
    if (!node) {
        return true;
    }
    if (node->value == NULL || node->value[0] == '\0') {
        return false;
    }
    return true;
}

bool lint_tree_list(Node** node, int size) {
    if (size < 2) {
        return false;
    }
    if (node[0]->value == NULL || node[0]->value[0] != 's') {
        return false;
    }
    for (int i = 1; i < size; i++) {
        if (!lint_tree(node[i])) {
            return false;
        }
    }
    return true;
}

int main() {
    Node* tree[3];
    tree[0] = (Node*)malloc(sizeof(Node));
    tree[0]->value = "program";

    Node* statement[3];
    statement[0] = (Node*)malloc(sizeof(Node));
    statement[0]->value = "statement";

    Node* expression[3];
    expression[0] = (Node*)malloc(sizeof(Node));
    expression[0]->value = "expression";

    Node* var = (Node*)malloc(sizeof(Node));
    var->value = "var";

    Node* value = (Node*)malloc(sizeof(Node));
    value->value = "value";

    expression[1] = var;
    expression[2] = value;
    statement[1] = (Node*)expression;
    statement[2] = NULL;
    tree[1] = (Node*)statement;
    tree[2] = NULL;

    printf("%d\n", lint_tree_list(tree, 2));

    free(tree[0]);
    free(statement[0]);
    free(expression[0]);
    free(var);
    free(value);
    free(tree[1]);
    free(statement[1]);

    return 0;
}