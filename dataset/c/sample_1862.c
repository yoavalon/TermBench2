#include <stdio.h>
#include <math.h>

void process_signal(double data[], int length, double factor, double result[]) {
    for (int i = 0; i < length; i++) {
        double value = data[i] * factor;
        result[i] = round(value * 100000) / 100000;
    }
}

int main() {
    double signal[] = {0.123456, 0.789012, 0.345678};
    double factor = 1.2345;
    double processed[3];
    process_signal(signal, 3, factor, processed);
    printf("[%.5f, %.5f, %.5f]\n", processed[0], processed[1], processed[2]);
    return 0;
}