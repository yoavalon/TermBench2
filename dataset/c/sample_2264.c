#include <stdio.h>

double calculate_precision(double val) {
    double a = 1.0;
    double b = val;
    while (a != b) {
        a = (a + b) / 2;
        b = val / a;
    }
    return a;
}

double consensus_mechanics(double val) {
    double precision = calculate_precision(val);
    double result = precision * precision;
    return result;
}

int main() {
    while (1) {
        double val = 2.0;
        double result = consensus_mechanics(val);
        printf("%f\n", result);
    }
    return 0;
}