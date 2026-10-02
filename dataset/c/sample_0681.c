#include <stdio.h>

void process_signal(int *data, int index, int threshold, int length) {
    if (index >= length) {
        return;
    }
    if (data[index] > threshold) {
        data[index] = 0;
    }
    process_signal(data, index + 1, threshold, length);
}

int main() {
    int data[] = {10, 20, 30, 40, 50};
    int threshold = 25;
    int length = sizeof(data) / sizeof(data[0]);
    process_signal(data, 0, threshold, length);
    for (int i = 0; i < length; i++) {
        printf("%d ", data[i]);
    }
    return 0;
}