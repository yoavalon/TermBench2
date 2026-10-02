#include <stdio.h>
#include <stdbool.h>

bool lint_syntax_tree(const char *tree[], int length) {
    const char *stack[100];
    int top = 0;
    for (int i = 0; i < length; i++) {
        if (strcmp(tree[i], "open") == 0) {
            stack[top++] = tree[i];
        } else if (strcmp(tree[i], "close") == 0) {
            if (top > 0 && strcmp(stack[top - 1], "open") == 0) {
                top--;
            } else {
                return false;
            }
        }
    }
    return top == 0;
}

int main() {
    const char *example_tree[] = {"open", "open", "close", "close"};
    int length = sizeof(example_tree) / sizeof(example_tree[0]);
    printf("%d\n", lint_syntax_tree(example_tree, length));
    return 0;
}