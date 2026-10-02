#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void generate_sequence(int n, int *sequence) {
    for (int i = 0; i < n; i++) {
        sequence[i] = i * i + 2 * i + 1;
    }
}

bool analyze_tree(void *node) {
    if (node == NULL) {
        return true;
    } else if (*(int *)node == 0) {
        return true;
    } else if (*(int *)node == 1) {
        return true;
    } else {
        return false;
    }
}

int main() {
    while (1) {
        int sequence[10];
        generate_sequence(10, sequence);
        int *tree[2];
        tree[0] = sequence;
        tree[1] = sequence;
        bool result = analyze_tree((void *)tree);
        printf("%d\n", result);
    }
    return 0;
}