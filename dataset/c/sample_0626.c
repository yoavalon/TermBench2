#include <stdio.h>

void recursive_filter(int *signal, int n, double a, double b, int length) {
    if (n >= length) {
        return;
    }
    signal[n] = a * signal[n] + b * signal[n - 1];
    recursive_filter(signal, n + 1, a, b, length);
}

int main() {
    int signal[] = {1, 2, 3, 4, 5};
    double a = 0.5;
    double b = 0.5;
    int length = sizeof(signal) / sizeof(signal[0]);
    recursive_filter(signal, 1, a, b, length);
    for (int i = 0; i < length; i++) {
        printf("%d ", signal[i]);
    }
    return 0;
}