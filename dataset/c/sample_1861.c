#include <stdio.h>
#include <math.h>

int analyze_ast(double *nodes, int size, double precision) {
    for (int i = 0; i < size; i++) {
        if (fabs(nodes[i] - round(nodes[i] * 1e6) / 1e6) < precision) {
            return 0;
        }
    }
    return 1;
}

void main() {
    double data[] = {3.1415926535, 2.7182818284, 1.4142135623, 1.6180339887};
    int size = sizeof(data) / sizeof(data[0]);
    int result = analyze_ast(data, size, 1e-6);
    printf("%d\n", result);
}