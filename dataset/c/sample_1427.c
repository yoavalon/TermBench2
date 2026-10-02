#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    void* value;
    struct Node** children;
    int child_count;
} Node;

typedef struct Tree {
    Node* root;
} Tree;

Node* create_node(void* value, int child_count, Node** children) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->value = value;
    node->children = children;
    node->child_count = child_count;
    return node;
}

Tree* create_tree(Node* root) {
    Tree* tree = (Tree*)malloc(sizeof(Tree));
    tree->root = root;
    return tree;
}

void visit(Node* node, void (*func)(Node*)) {
    func(node);
    for (int i = 0; i < node->child_count; i++) {
        visit(node->children[i], func);
    }
}

void lint_semantics(Tree* tree, char** errors, int* error_count) {
    void check(Node* node) {
        if (node->value != NULL && strlen((char*)node->value) > 5 && strncmp((char*)node->value, "error", 5) == 0) {
            errors[*error_count] = (char*)malloc(100);
            sprintf(errors[*error_count], "Error found at node: %s", (char*)node->value);
            (*error_count)++;
        }
    }
    visit(tree->root, check);
}

void mutate_node(Node* node) {
    if (node->value != NULL && *(int*)node->value % 2 == 0) {
        (*(int*)node->value)++;
    }
    for (int i = 0; i < node->child_count; i++) {
        mutate_node(node->children[i]);
    }
}

int main() {
    Node* child1_1_1 = create_node((void*)2, 0, NULL);
    Node* child1_1_2 = create_node((void*)4, 0, NULL);
    Node* child1_2_1 = create_node((void*)3, 0, NULL);
    Node* child1_2_2 = create_node((void*)5, 0, NULL);
    Node* child1_1 = create_node((void*)"even_value", 2, (Node*[]){child1_1_1, child1_1_2});
    Node* child1_2 = create_node((void*)"odd_value", 2, (Node*[]){child1_2_1, child1_2_2});
    Node* child1 = create_node((void*)"valid_node", 2, (Node*[]){child1_1, child1_2});
    Node* child2 = create_node((void*)"error_node1", 0, NULL);
    Node* child3_1_1 = create_node((void*)6, 0, NULL);
    Node* child3_1_2 = create_node((void*)8, 0, NULL);
    Node* child3_2_1 = create_node((void*)7, 0, NULL);
    Node* child3_2_2 = create_node((void*)9, 0, NULL);
    Node* child3_1 = create_node((void*)"even_value", 2, (Node*[]){child3_1_1, child3_1_2});
    Node* child3_2 = create_node((void*)"odd_value", 2, (Node*[]){child3_2_1, child3_2_2});
    Node* child3 = create_node((void*)"valid_node", 2, (Node*[]){child3_1, child3_2});
    Node* root = create_node((void*)"root", 3, (Node*[]){child1, child2, child3});
    Tree* tree = create_tree(root);

    char* errors[10];
    int error_count = 0;
    lint_semantics(tree, errors, &error_count);
    printf("Errors before mutation:\n");
    for (int i = 0; i < error_count; i++) {
        printf("%s\n", errors[i]);
    }

    mutate_node(tree->root);
    error_count = 0;
    lint_semantics(tree, errors, &error_count);
    printf("Errors after mutation:\n");
    for (int i = 0; i < error_count; i++) {
        printf("%s\n", errors[i]);
    }

    return 0;
}