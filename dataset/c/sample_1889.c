#include <stdio.h>
#include <math.h>

double round5(double value) {
    return round(value * 100000) / 100000;
}

double* process_signal(double* data, int size, double factor) {
    static double result[3];
    for (int i = 0; i < size; i++) {
        result[i] = data[i] * factor;
    }
    for (int i = 0; i < size; i++) {
        result[i] = round5(result[i]);
    }
    return result;
}

int main() {
    double signal[] = {0.123456789, 0.23456789, 0.345678901};
    double factor = 1.23456;
    double* processed = process_signal(signal, 3, factor);
    for (int i = 0; i < 3; i++) {
        printf("%f ", processed[i]);
    }
    printf("\n");
    return 0;
}