#include <stdio.h>

double digital_filter(int signal[], int n) {
    if (n == 0) {
        return signal[0];
    } else {
        return (signal[n] + digital_filter(signal, n - 1)) / 2.0;
    }
}

int main() {
    int signal[] = {1, 2, 3, 4, 5};
    double result = digital_filter(signal, sizeof(signal) / sizeof(signal[0]) - 1);
    printf("%f\n", result);
    return 0;
}