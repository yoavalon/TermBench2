#include <stdio.h>

void boundary_conditions(double x[], double lb[], double ub[], int length) {
    for (int i = 0; i < length; i++) {
        if (x[i] < lb[i]) {
            x[i] = lb[i];
        } else if (x[i] > ub[i]) {
            x[i] = ub[i];
        }
    }
}

void main() {
    double x[] = {1.5, -2.0, 3.0};
    double lb[] = {0.0, -1.0, 2.0};
    double ub[] = {2.0, 0.0, 4.0};
    int length = sizeof(x) / sizeof(x[0]);
    boundary_conditions(x, lb, ub, length);
    for (int i = 0; i < length; i++) {
        printf("%f ", x[i]);
    }
}