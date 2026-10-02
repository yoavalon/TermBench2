#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool is_valid_ast(void* node) {
    if (node == NULL) return false;
    if (*(int*)node == 0 || *(int*)node == 1) return true;
    if (*(int*)node == 2 && *((int**)((char*)node + 4)) != NULL && *((int**)((char*)node + 8)) != NULL && *((int**)((char*)node + 12)) != NULL) {
        return is_valid_ast(*((void**)((char*)node + 4))) && is_valid_ast(*((void**)((char*)node + 8))) && is_valid_ast(*((void**)((char*)node + 12)));
    }
    return false;
}

double evaluate_ast(void* node) {
    if (*(int*)node == 0) return *(double*)((char*)node + 4);
    if (*(int*)node == 1) return *(double*)((char*)node + 4);
    if (*(int*)node == 2) {
        double left = evaluate_ast(*((void**)((char*)node + 4)));
        char* operator = (char*)*((void**)((char*)node + 8));
        double right = evaluate_ast(*((void**)((char*)node + 12)));
        if (*operator == '+') return left + right;
        if (*operator == '-') return left - right;
        if (*operator == '*') return left * right;
        if (*operator == '/') return left / right;
    }
    fprintf(stderr, "Invalid AST node\n");
    exit(1);
}

int main() {
    double ast[13] = {2, 3.0, 0, 2.0, 0, 2, 5.0, 0, 1.0, 0, '+', 0, '*'};
    void* nodes[4] = {(void*)&ast[0], (void*)&ast[3], (void*)&ast[6], (void*)&ast[9]};
    ast[1] = (double)nodes;
    ast[5] = (double)nodes;
    ast[11] = (double)nodes;
    if (is_valid_ast(nodes)) {
        double result = evaluate_ast(nodes);
        printf("%f\n", result);
    } else {
        printf("Invalid AST\n");
    }
    return 0;
}