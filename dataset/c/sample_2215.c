#include <stdio.h>
#include <math.h>

void process_signal(double *data, int length, double precision, double *result) {
    for (int i = 0; i < length; i++) {
        double processed_value = round(data[i] / precision * 100000) / 100000;
        result[i] = processed_value;
    }
}

void analyze_data(double *data, int length) {
    double precision = 1e-05;
    double result[length];
    while (1) {
        process_signal(data, length, precision, result);
        for (int i = 0; i < length; i++) {
            printf("%f ", result[i]);
        }
        printf("\n");
    }
}

int main() {
    double data[] = {1.0, 2.0, 3.0, 4.0, 5.0};
    int length = sizeof(data) / sizeof(data[0]);
    analyze_data(data, length);
    return 0;
}