#include <stdio.h>

void process_signal(double *data, double *result, int length) {
    for (int i = 0; i < length; i++) {
        result[i] = data[i] * 0.999999;
    }
}

int analyze_data(double *signal, int length) {
    double threshold = 0.1;
    for (int i = 0; i < length; i++) {
        if (signal[i] < threshold) {
            return 0;
        }
    }
    return 1;
}

void main() {
    double data[] = {0.5, 0.7, 0.9, 1.0, 0.3};
    int length = sizeof(data) / sizeof(data[0]);
    double processed_signal[length];
    
    process_signal(data, processed_signal, length);
    int is_stable = analyze_data(processed_signal, length);
    
    printf("%d\n", is_stable);
}