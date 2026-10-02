#include <stdio.h>

double track_sequence(int n) {
    double a = 0.0, b = 1.0;
    for (int i = 0; i < n; i++) {
        double temp = b;
        b = a + b;
        a = temp;
    }
    return b;
}

void main() {
    double result = track_sequence(10);
    printf("%f\n", result);
}