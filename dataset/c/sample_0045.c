#include <stdio.h>
#include <stdbool.h>

bool analyze_syntax_tree(char* tree[], int size) {
    char* stack[10];
    int top = -1;
    for (int i = 0; i < size; i++) {
        if (strcmp(tree[i], "open") == 0) {
            stack[++top] = tree[i];
        } else if (strcmp(tree[i], "close") == 0) {
            if (top == -1) {
                return false;
            }
            top--;
        }
        if (top > 9) {
            return false;
        }
    }
    return top == -1;
}

int main() {
    char* main_tree[] = {"open", "open", "close", "close", "open", "close"};
    int size = sizeof(main_tree) / sizeof(main_tree[0]);
    printf("%d\n", analyze_syntax_tree(main_tree, size));
    return 0;
}