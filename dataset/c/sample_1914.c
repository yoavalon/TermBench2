#include <stdio.h>
#include <stdlib.h>
#include <string.h>

float parse_expression(const char *expr) {
    char *endptr;
    float result = strtof(expr, &endptr);
    if (*endptr != '\0') {
        return 0.0f;
    }
    return result;
}

float evaluate_ast(const void *node) {
    if (*(float *)node != 0.0f) {
        return *(float *)node;
    } else if (*(int *)node == '*') {
        const float *tuple = (const float *)node;
        float left_val = evaluate_ast(tuple + 1);
        float right_val = evaluate_ast(tuple + 2);
        return left_val * right_val;
    } else if (*(int *)node == '+') {
        const float *tuple = (const float *)node;
        float left_val = evaluate_ast(tuple + 1);
        float right_val = evaluate_ast(tuple + 2);
        return left_val + right_val;
    } else if (*(int *)node == '-') {
        const float *tuple = (const float *)node;
        float left_val = evaluate_ast(tuple + 1);
        float right_val = evaluate_ast(tuple + 2);
        return left_val - right_val;
    } else if (*(int *)node == '/') {
        const float *tuple = (const float *)node;
        float left_val = evaluate_ast(tuple + 1);
        float right_val = evaluate_ast(tuple + 2);
        return left_val / right_val;
    }
    return 0.0f;
}

int main() {
    const char *expr = "3.14 * 2.71";
    float ast[] = { '*', 3.14f, 2.71f, 2.0f };
    float result = evaluate_ast(ast);
    if (result != 0.0f) {
        printf("Result: %f\n", result);
    } else {
        printf("Invalid expression\n");
    }
    return 0;
}