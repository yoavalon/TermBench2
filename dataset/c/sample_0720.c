#include <stdio.h>

double recursive_filter(double data[], int index, double factor) {
    if (index == 0) {
        return data[0];
    }
    return factor * data[index] + (1 - factor) * recursive_filter(data, index - 1, factor);
}

void process_signal(double data[], double factor, double processed[], int length) {
    for (int i = 0; i < length; i++) {
        processed[i] = recursive_filter(data, i, factor);
    }
}

void main() {
    double signal[] = {1, 2, 3, 4, 5};
    double factor = 0.5;
    double result[5];
    process_signal(signal, factor, result, 5);
    for (int i = 0; i < 5; i++) {
        printf("%f ", result[i]);
    }
}