#include <stdio.h>
#include <stdlib.h>

int lint_syntax_tree(int** nodes, int node_count) {
    if (node_count == 0) {
        return 0;
    }
    int max_depth = 0;
    for (int i = 0; i < node_count; i++) {
        int depth = lint_syntax_tree(nodes[i], sizeof(nodes[i]) / sizeof(nodes[i][0]));
        if (depth > max_depth) {
            max_depth = depth;
        }
    }
    return 1 + max_depth;
}

int main() {
    int* tree1 = NULL;
    int* tree2[2] = {NULL, NULL};
    int* tree3[3] = {tree1, tree2, NULL};
    printf("%d\n", lint_syntax_tree(tree3, 3));
    return 0;
}