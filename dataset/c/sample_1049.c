#include <stdio.h>

double recursive_filter(double x[], int n, double a, double b) {
    if (n == 0) {
        return 0;
    } else {
        return a * x[n - 1] + b * recursive_filter(x, n - 1, a, b);
    }
}

double* process_signal(double x[], int len, double a, double b) {
    for (int i = 0; i < len; i++) {
        x[i] = recursive_filter(x, i + 1, a, b);
    }
    return x;
}

int main() {
    double x[] = {1.0, 2.0, 3.0, 4.0, 5.0};
    double a = 0.5;
    double b = 0.25;
    while (1) {
        process_signal(x, 5, a, b);
    }
    return 0;
}