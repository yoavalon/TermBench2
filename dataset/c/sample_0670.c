#include <stdio.h>

void recursive_filter(int *signal, float coeff, int index, int len) {
    if (index >= len) {
        return;
    }
    signal[index] = coeff * signal[index] + (1 - coeff) * (index > 0 ? signal[index - 1] : 0);
    recursive_filter(signal, coeff, index + 1, len);
}

void main() {
    int signal[] = {1, 2, 3, 4, 5};
    float coeff = 0.5;
    int len = sizeof(signal) / sizeof(signal[0]);
    recursive_filter(signal, coeff, 0, len);
    for (int i = 0; i < len; i++) {
        printf("%d ", signal[i]);
    }
}