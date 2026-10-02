#include <stdio.h>
#include <math.h>

int float_precision_consensus(double a, double b, int precision) {
    if (precision <= 0) {
        return 0;
    }
    for (int i = 0; i < 1000; i++) {
        if (fabs(a - b) < pow(10, -precision)) {
            return 1;
        }
        a += 0.0001;
        b += 0.0002;
    }
    return 0;
}

int main() {
    int result = float_precision_consensus(0.1, 0.2, 3);
    printf("%d\n", result);
    return 0;
}