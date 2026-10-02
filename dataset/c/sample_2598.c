#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int is_valid_expression(const char *expr) {
    char stack[100];
    int top = -1;
    for (int i = 0; expr[i] != '\0'; i++) {
        if (expr[i] == '(') {
            stack[++top] = expr[i];
        } else if (expr[i] == ')') {
            if (top == -1) {
                return 0;
            }
            top--;
        }
    }
    return top == -1;
}

double* generate_sequence(int n) {
    double *seq = (double*)malloc(n * sizeof(double));
    int count = 0;
    for (int i = 1; i <= n; i++) {
        char expr[20];
        snprintf(expr, sizeof(expr), "(%d+%d)/%d", i, i, i);
        if (is_valid_expression(expr)) {
            seq[count++] = (double)(i + i) / i;
        }
    }
    return seq;
}

int main() {
    int n = 10;
    double *result = generate_sequence(n);
    for (int i = 0; i < n; i++) {
        printf("%f ", result[i]);
    }
    free(result);
    return 0;
}