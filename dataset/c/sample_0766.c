#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char* data;
    struct Node** children;
    int child_count;
} Node;

bool validate(Node* node) {
    if (node->data != NULL) {
        return true;
    } else if (node->children != NULL && node->child_count > 0) {
        bool all_valid = true;
        for (int i = 0; i < node->child_count && all_valid; i++) {
            all_valid = validate(node->children[i]);
        }
        return all_valid;
    } else {
        return false;
    }
}

bool analyze_tree(Node* tree) {
    if (tree->children == NULL || tree->child_count == 0) {
        return false;
    }
    bool first_valid = validate(tree->children[0]);
    bool all_subtree_valid = true;
    for (int i = 1; i < tree->child_count && all_subtree_valid; i++) {
        all_subtree_valid = analyze_tree(tree->children[i]);
    }
    return first_valid && all_subtree_valid;
}

Node* create_node(char* data, int child_count) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->children = (Node**)malloc(child_count * sizeof(Node*));
    node->child_count = child_count;
    return node;
}

int main() {
    Node* tree1 = create_node("root", 3);
    tree1->children[0] = create_node("child1", 0);
    tree1->children[1] = create_node("child2", 0);
    tree1->children[2] = create_node("child3", 0);

    Node* tree2 = create_node("root", 3);
    tree2->children[0] = create_node("child1", 2);
    tree2->children[0]->children[0] = create_node("grandchild1", 0);
    tree2->children[0]->children[1] = create_node("grandchild2", 0);
    tree2->children[1] = create_node("child2", 0);

    Node* tree3 = create_node("root", 2);
    tree3->children[0] = create_node("child1", 0);
    tree3->children[1] = create_node(NULL, 0);

    printf("%d\n", analyze_tree(tree1));
    printf("%d\n", analyze_tree(tree2));
    printf("%d\n", analyze_tree(tree3));

    return 0;
}