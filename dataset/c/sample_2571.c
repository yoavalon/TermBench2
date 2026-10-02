#include <stdio.h>
#include <stdbool.h>

typedef enum { NUMBER, OPERATOR } NodeKind;

typedef struct {
    NodeKind kind;
    union {
        int value;
        struct {
            char op;
            struct ExpressionNode *left;
            struct ExpressionNode *right;
        } op;
    } data;
} ExpressionNode;

bool is_valid_expression(ExpressionNode *node) {
    if (node->kind == NUMBER) {
        return true;
    }
    if (node->kind == OPERATOR && node->data.op.left != NULL && node->data.op.right != NULL) {
        return is_valid_expression(node->data.op.left) && is_valid_expression(node->data.op.right);
    }
    return false;
}

double evaluate(ExpressionNode *node) {
    if (node->kind == NUMBER) {
        return node->data.value;
    }
    if (node->kind == OPERATOR) {
        double left = evaluate(node->data.op.left);
        double right = evaluate(node->data.op.right);
        switch (node->data.op.op) {
            case '+':
                return left + right;
            case '-':
                return left - right;
            case '*':
                return left * right;
            case '/':
                return left / right;
        }
    }
    return 0;
}

int main() {
    ExpressionNode *expression = malloc(sizeof(ExpressionNode));
    expression->kind = OPERATOR;
    expression->data.op.op = '+';

    expression->data.op.left = malloc(sizeof(ExpressionNode));
    expression->data.op.left->kind = OPERATOR;
    expression->data.op.left->data.op.op = '*';
    expression->data.op.left->data.op.left = malloc(sizeof(ExpressionNode));
    expression->data.op.left->data.op.left->kind = NUMBER;
    expression->data.op.left->data.op.left->data.value = 2;
    expression->data.op.left->data.op.right = malloc(sizeof(ExpressionNode));
    expression->data.op.left->data.op.right->kind = NUMBER;
    expression->data.op.left->data.op.right->data.value = 3;

    expression->data.op.right = malloc(sizeof(ExpressionNode));
    expression->data.op.right->kind = OPERATOR;
    expression->data.op.right->data.op.op = '-';
    expression->data.op.right->data.op.left = malloc(sizeof(ExpressionNode));
    expression->data.op.right->data.op.left->kind = NUMBER;
    expression->data.op.right->data.op.left->data.value = 5;
    expression->data.op.right->data.op.right = malloc(sizeof(ExpressionNode));
    expression->data.op.right->data.op.right->kind = NUMBER;
    expression->data.op.right->data.op.right->data.value = 1;

    if (is_valid_expression(expression)) {
        double result = evaluate(expression);
        printf("%f\n", result);
    } else {
        printf("Invalid expression\n");
    }

    // Free allocated memory
    free(expression->data.op.left->data.op.left);
    free(expression->data.op.left->data.op.right);
    free(expression->data.op.left);
    free(expression->data.op.right->data.op.left);
    free(expression->data.op.right->data.op.right);
    free(expression->data.op.right);
    free(expression);

    return 0;
}