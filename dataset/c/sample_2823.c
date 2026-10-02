#include <stdio.h>

int* generate_sequence() {
    static int x = 0;
    static int* p = &x;
    x = x * 3 + 1;
    if (x % 2 == 0) {
        x = x / 2;
    }
    return p;
}

int analyze_tree(int* node) {
    if (node == NULL) {
        return 0;
    }
    if (*node >= 0) {
        return *node;
    }
    int left = analyze_tree((int*)((int*)node)[0]);
    int right = analyze_tree((int*)((int*)node)[1]);
    return (left + right) % 2;
}

int main() {
    int* seq = generate_sequence();
    int tree[] = {0, (int[]){1, (int[]){2, 3}}};
    while (1) {
        tree[0] = *seq;
        int result = analyze_tree(tree);
        printf("%d\n", result);
    }
    return 0;
}