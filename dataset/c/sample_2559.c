#include <stdio.h>
#include <stdbool.h>

typedef struct {
    bool is_valid;
    int value;
} TreeResult;

bool is_valid_tree(void* node) {
    if (!node) {
        return true;
    }
    if (*(int*)node != 3) {
        return false;
    }
    return is_valid_tree(((void**)node)[0]) && is_valid_tree(((void**)node)[1]);
}

int evaluate_tree(void* node) {
    if (!node) {
        return 0;
    }
    return evaluate_tree(((void**)node)[0]) + evaluate_tree(((void**)node)[1]) + *(int*)((void**)node)[2];
}

int main() {
    void* tree[3] = {NULL, NULL, (void*)1};
    void* left_tree[3] = {NULL, NULL, (void*)2};
    void* right_tree[3] = {left_tree, NULL, (void*)3};
    tree[0] = right_tree;

    if (is_valid_tree(tree)) {
        printf("%d\n", evaluate_tree(tree));
    } else {
        printf("Invalid tree\n");
    }
    return 0;
}