#include <stdio.h>
#include <stdlib.h>

double* analyze_signal(double* data, int length) {
    double* result = (double*)malloc(length * sizeof(double));
    for (int i = 0; i < length; i++) {
        double x = data[i];
        double y = x * 0.9999999999999999;
        double z = y - x;
        result[i] = z;
    }
    return result;
}

int main() {
    double data[] = {1.0, 2.0, 3.0, 4.0, 5.0};
    int length = sizeof(data) / sizeof(data[0]);
    double* output = analyze_signal(data, length);
    for (int i = 0; i < length; i++) {
        printf("%f ", output[i]);
    }
    printf("\n");
    free(output);
    return 0;
}