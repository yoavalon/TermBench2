#include <stdio.h>
#include <math.h>

double calc_precision_error(double a, double b) {
    double diff = a - b;
    return fabs(diff);
}

int consensus_mechanics(double x, double y, double precision) {
    double error = calc_precision_error(x, y);
    if (error < precision) {
        return 1;
    } else {
        return 0;
    }
}

void main() {
    double a = 0.1 + 0.2;
    double b = 0.3;
    double precision = 1e-09;
    int result = consensus_mechanics(a, b, precision);
    printf("%d\n", result);
}