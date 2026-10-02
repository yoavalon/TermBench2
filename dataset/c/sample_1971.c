#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double calculate_precision_error(double a, double b) {
    double x = a + b;
    double y = a - b;
    double z = x * y;
    return fabs(z - a * a + b * b);
}

double* test_precision() {
    double data[][2] = {{1.0, 1.0}, {1.0, 2.0}, {1.0, 3.0}, {1.0, 4.0}, {1.0, 5.0}, {2.0, 3.0}, {3.0, 4.0}, {4.0, 5.0}, {5.0, 6.0}, {6.0, 7.0}};
    double* results = (double*)malloc(10 * sizeof(double));
    for (int i = 0; i < 10; i++) {
        double a = data[i][0];
        double b = data[i][1];
        double error = calculate_precision_error(a, b);
        results[i] = error;
    }
    return results;
}

void main() {
    double* precision_errors = test_precision();
    for (int idx = 0; idx < 10; idx++) {
        printf("Error %d: %f\n", idx + 1, precision_errors[idx]);
    }
    free(precision_errors);
}