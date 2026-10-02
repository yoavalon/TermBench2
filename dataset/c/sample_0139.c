#include <stdio.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
    char type[20];
    char name[20];
    char op[2];
    int value;
    int params[10];
    int params_count;
    struct Node* children[10];
    int children_count;
} Node;

bool validate_function(Node node) {
    if (node.params_count != -1 && node.params_count != 2) {
        return false;
    }
    if (node.children_count != -1 && node.children_count != 1) {
        return false;
    }
    return true;
}

bool validate_node(Node node) {
    if (strcmp(node.type, "dict") == 0) {
        for (int i = 0; i < node.children_count; i++) {
            Node child = node.children[i];
            if (strcmp(child.type, "function") == 0) {
                if (!validate_function(child)) {
                    return false;
                }
            } else if (strcmp(child.type, "children") == 0) {
                for (int j = 0; j < child.children_count; j++) {
                    if (!validate_node(child.children[j])) {
                        return false;
                    }
                }
            }
        }
    }
    return true;
}

int main() {
    Node tree;
    strcpy(tree.type, "program");
    tree.children_count = 1;

    Node function;
    strcpy(function.type, "function");
    function.params[0] = 'a';
    function.params[1] = 'b';
    function.params_count = 2;
    function.children_count = 1;

    Node return_node;
    strcpy(return_node.type, "return");
    return_node.children_count = 1;

    Node binary;
    strcpy(binary.type, "binary");
    strcpy(binary.op, "+");
    return_node.children[0] = binary;

    Node left_var;
    strcpy(left_var.type, "var");
    strcpy(left_var.name, "a");
    binary.children[0] = left_var;

    Node right_var;
    strcpy(right_var.type, "var");
    strcpy(right_var.name, "b");
    binary.children[1] = right_var;

    function.children[0] = return_node;
    tree.children[0] = function;

    printf("%d\n", validate_node(tree));
    return 0;
}