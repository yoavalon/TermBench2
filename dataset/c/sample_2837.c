#include <stdio.h>

void* calculate_trajectory() {
    double a = 0.001;
    double b = 0.002;
    double h = 10000;
    double v = 200;
    static double result[2];
    while (1) {
        result[0] = h;
        result[1] = v;
        h -= a;
        v -= b;
        if (h <= 0) {
            h = 10000;
            v = 200;
        }
        yield(result);
    }
}

void analyze_data() {
    int i = 0;
    double result[2];
    while (1) {
        calculate_trajectory(result);
        printf("Step %d: Altitude %.2fm, Velocity %.2fm/s\n", i, result[0], result[1]);
        i++;
    }
}

void main() {
    analyze_data();
}