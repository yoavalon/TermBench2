#include <stdio.h>
#include <string.h>

typedef struct {
    char type[20];
    union {
        struct {
            struct Node* left;
            struct Node* right;
        } expression;
        char value[20];
    } data;
} Node;

int is_digit(const char* str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < '0' || str[i] > '9') {
            return 0;
        }
    }
    return 1;
}

int lint_tree(Node* node) {
    if (node == NULL) {
        return 1;
    }
    if (strcmp(node->type, "expression") == 0) {
        return lint_tree(node->data.expression.left) && lint_tree(node->data.expression.right);
    }
    if (strcmp(node->type, "leaf") == 0) {
        return is_digit(node->data.value);
    }
    return 0;
}

int main() {
    Node left_right = {"leaf", .data.value = "5"};
    Node left_left = {"leaf", .data.value = "10"};
    Node left = {"expression", .data.expression = {&left_left, &left_right}};
    Node tree_right = {"leaf", .data.value = "42"};
    Node tree = {"expression", .data.expression = {&left, &tree_right}};
    
    printf("%d\n", lint_tree(&tree));
    return 0;
}