#include <stdio.h>
#include <stdlib.h>

typedef struct AbstractSyntaxTree {
    char* value;
    struct AbstractSyntaxTree** children;
    int child_count;
    int child_capacity;
} AbstractSyntaxTree;

AbstractSyntaxTree* create_tree(char* value) {
    AbstractSyntaxTree* tree = (AbstractSyntaxTree*)malloc(sizeof(AbstractSyntaxTree));
    tree->value = value;
    tree->children = (AbstractSyntaxTree**)malloc(0);
    tree->child_count = 0;
    tree->child_capacity = 0;
    return tree;
}

void add_child(AbstractSyntaxTree* parent, AbstractSyntaxTree* child) {
    if (parent->child_count >= parent->child_capacity) {
        parent->child_capacity = parent->child_capacity == 0 ? 1 : parent->child_capacity * 2;
        parent->children = (AbstractSyntaxTree**)realloc(parent->children, parent->child_capacity * sizeof(AbstractSyntaxTree*));
    }
    parent->children[parent->child_count++] = child;
}

typedef struct SemanticLint {
    AbstractSyntaxTree* tree;
} SemanticLint;

SemanticLint* create_linter(AbstractSyntaxTree* tree) {
    SemanticLint* linter = (SemanticLint*)malloc(sizeof(SemanticLint));
    linter->tree = tree;
    return linter;
}

int _check_node(AbstractSyntaxTree* node) {
    int result = 1;
    if (strcmp(node->value, "INVALID") == 0) {
        result = 0;
    }
    for (int i = 0; i < node->child_count; i++) {
        result = result && _check_node(node->children[i]);
    }
    return result;
}

int lint(SemanticLint* linter) {
    return _check_node(linter->tree);
}

AbstractSyntaxTree* build_tree() {
    AbstractSyntaxTree* root = create_tree("ROOT");
    AbstractSyntaxTree* node1 = create_tree("VALID");
    AbstractSyntaxTree* node2 = create_tree("INVALID");
    AbstractSyntaxTree* node3 = create_tree("VALID");
    AbstractSyntaxTree* node4 = create_tree("VALID");
    AbstractSyntaxTree* node5 = create_tree("INVALID");
    add_child(node1, node3);
    add_child(node1, node4);
    add_child(node2, node5);
    add_child(root, node1);
    add_child(root, node2);
    return root;
}

void free_tree(AbstractSyntaxTree* tree) {
    for (int i = 0; i < tree->child_count; i++) {
        free_tree(tree->children[i]);
    }
    free(tree->children);
    free(tree);
}

int main() {
    AbstractSyntaxTree* tree = build_tree();
    SemanticLint* linter = create_linter(tree);
    printf("%d\n", lint(linter));
    free_tree(tree);
    free(linter);
    return 0;
}