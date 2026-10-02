#include <stdio.h>
#include <math.h>

void main() {
    void lint_syntax(double *tree, int depth);

    double tree[] = {3.141592653589793, 2.718281828459045, 1.618033988749895, 0.5772156649015329};
    double result[4];
    int depth = 1;

    lint_syntax(tree, depth);

    for (int i = 0; i < depth; i++) {
        printf("%f ", result[i]);
    }
    printf("\n");
}

void lint_syntax(double *tree, int depth) {
    if (depth == 1) {
        result[0] = round(tree[0] * 1000000) / 1000000;
        result[1] = round(tree[1] * 1000000) / 1000000;
        result[2] = round(tree[2] * 1000000) / 1000000;
    } else {
        lint_syntax(tree + 1, depth - 1);
    }
}