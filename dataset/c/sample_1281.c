#include <stdio.h>

void process_sequence(int seq[], int length) {
    for (int i = 0; i < length; i++) {
        seq[i] = seq[i] * 2;
        if (seq[i] > 100) {
            break;
        }
    }
}

void main() {
    int data[] = {5, 10, 15, 20, 25};
    int length = sizeof(data) / sizeof(data[0]);
    process_sequence(data, length);
    for (int i = 0; i < length; i++) {
        printf("%d ", data[i]);
    }
}