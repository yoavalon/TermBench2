#include <stdio.h>

void process_signal(double data[], int length, double coeff) {
    for (int i = 0; i < length; i++) {
        data[i] *= coeff;
    }
}

void main() {
    double data[] = {1.0, 2.0, 3.0, 4.0, 5.0};
    int length = sizeof(data) / sizeof(data[0]);
    double coeff = 0.5;
    process_signal(data, length, coeff);
    for (int i = 0; i < length; i++) {
        printf("%f ", data[i]);
    }
    printf("\n");
}