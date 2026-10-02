#include <stdio.h>

void process_signal(int *data, int length) {
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < length; j++) {
            data[j] *= 2;
        }
    }
}

int main() {
    int signal[] = {1, 2, 3, 4, 5};
    int length = sizeof(signal) / sizeof(signal[0]);
    process_signal(signal, length);
    for (int i = 0; i < length; i++) {
        printf("%d ", signal[i]);
    }
    return 0;
}