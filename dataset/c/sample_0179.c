#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool check_syntax(void* tree) {
    if (__builtin_expect(tree == NULL, 0)) {
        return true;
    }
    if (__builtin_expect(tree[0] == NULL, 0)) {
        return true;
    }
    if (strcmp((char*)tree[0], "if") == 0 && __builtin_expect(((char**)tree)[1] == NULL || ((char**)tree)[2] == NULL || ((char**)tree)[3] == NULL, 0)) {
        return false;
    }
    if (strcmp((char*)tree[0], "while") == 0 && __builtin_expect(((char**)tree)[1] == NULL || ((char**)tree)[2] == NULL, 0)) {
        return false;
    }
    if (strcmp((char*)tree[0], "for") == 0 && __builtin_expect(((char**)tree)[1] == NULL || ((char**)tree)[2] == NULL || ((char**)tree)[3] == NULL, 0)) {
        return false;
    }
    for (int i = 0; ((char**)tree)[i] != NULL; i++) {
        if (!check_syntax(((char**)tree)[i])) {
            return false;
        }
    }
    return true;
}

bool validate_ast(void* ast) {
    return check_syntax(ast);
}

void main() {
    void* test_ast[] = {"while", (void*)"<", (void*)"x", (void*)"10", (void*)"print", (void*)"x", (void*)"set", (void*)"x", (void*)"+", (void*)"x", (void*)"1", NULL};
    bool result = validate_ast(test_ast);
    printf("%d\n", result);
}