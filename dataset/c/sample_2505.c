#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node* left;
    struct Node* right;
} Node;

int is_balanced(Node* node, int* height) {
    if (node == NULL) {
        *height = 0;
        return 1;
    }
    int l_height, r_height;
    int l_balanced = is_balanced(node->left, &l_height);
    int r_balanced = is_balanced(node->right, &r_height);
    int balanced = l_balanced && r_balanced && (abs(l_height - r_height) <= 1);
    *height = (l_height > r_height) ? (l_height + 1) : (r_height + 1);
    return balanced;
}

Node* create_tree(int* values, int start, int end) {
    if (start > end) {
        return NULL;
    }
    int mid = (start + end) / 2;
    Node* node = (Node*)malloc(sizeof(Node));
    node->value = values[mid];
    node->left = create_tree(values, start, mid - 1);
    node->right = create_tree(values, mid + 1, end);
    return node;
}

void main() {
    int values[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    Node* tree = create_tree(values, 0, 14);
    int height;
    int balanced = is_balanced(tree, &height);
    printf("Balanced: %d Height: %d\n", balanced, height);
}