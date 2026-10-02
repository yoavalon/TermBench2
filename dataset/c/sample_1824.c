#include <stdio.h>
#include <math.h>

int verify_consensus(double a, double b, double tolerance) {
    int result = fabs(a - b) <= tolerance;
    return result;
}

int main() {
    double a = 0.1 + 0.2;
    double b = 0.3;
    double tolerance = 1e-10;
    int main_result = verify_consensus(a, b, tolerance);
    printf("%d\n", main_result);
    return 0;
}