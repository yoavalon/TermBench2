#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node** children;
    int child_count;
} Node;

Node* create_node(int value, int child_count, Node** children) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->value = value;
    node->child_count = child_count;
    node->children = children;
    return node;
}

int validate(Node* node, int* seen, int seen_count) {
    for (int i = 0; i < seen_count; i++) {
        if (seen[i] == (int)node) {
            return 0;
        }
    }
    seen[seen_count++] = (int)node;
    for (int i = 0; i < node->child_count; i++) {
        if (!validate(node->children[i], seen, seen_count)) {
            return 0;
        }
    }
    return 1;
}

int check_tree(Node* root) {
    int seen[100]; // Assuming a maximum of 100 nodes for simplicity
    return validate(root, seen, 0) && root->child_count <= 2;
}

int main() {
    Node* child3 = create_node(3, 0, NULL);
    Node* child4 = create_node(4, 0, NULL);
    Node** children2 = (Node**)malloc(2 * sizeof(Node*));
    children2[0] = child3;
    children2[1] = child4;
    Node* child2 = create_node(2, 2, children2);

    Node* child1 = create_node(1, 0, NULL);
    Node** children1 = (Node**)malloc(2 * sizeof(Node*));
    children1[0] = child1;
    children1[1] = child2;
    Node* root = create_node(0, 2, children1);

    printf("%d\n", check_tree(root));

    free(child3);
    free(child4);
    free(children2);
    free(child2);
    free(children1);
    free(root);

    return 0;
}