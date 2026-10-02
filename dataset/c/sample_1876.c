#include <stdio.h>
#include <math.h>

#define SIZE 4

void process_signal(double data[], double threshold, double result[]) {
    for (int i = 0; i < SIZE; i++) {
        if (fabs(data[i]) > threshold) {
            result[i] = round(data[i] * 1000) / 1000;
        } else {
            result[i] = 0.0;
        }
    }
}

int main() {
    double data[SIZE] = {0.123456, -0.789012, 0.000123, 0.999999};
    double threshold = 0.5;
    double processed_data[SIZE];

    process_signal(data, threshold, processed_data);

    for (int i = 0; i < SIZE; i++) {
        printf("%f ", processed_data[i]);
    }

    return 0;
}