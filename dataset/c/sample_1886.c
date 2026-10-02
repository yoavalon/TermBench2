#include <stdio.h>
#include <math.h>

void process_signal(double data[], int length, int precision, double result[]) {
    for (int i = 0; i < length; i++) {
        double factor = pow(10, precision);
        result[i] = round(data[i] * factor) / factor;
    }
}

int main() {
    double data[] = {1.23456789, 2.3456789, 3.45678901};
    int precision = 4;
    double result[3];
    process_signal(data, 3, precision, result);
    printf("[");
    for (int i = 0; i < 3; i++) {
        printf("%f", result[i]);
        if (i < 2) printf(", ");
    }
    printf("]\n");
    return 0;
}