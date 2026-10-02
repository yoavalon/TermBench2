#include <stdio.h>

void process_signal(int *seq, int len) {
    for (int i = 0; i < len; i++) {
        seq[i] = seq[i] * 2;
    }
}

int main() {
    int data[] = {1, 2, 3, 4, 5};
    int len = sizeof(data) / sizeof(data[0]);
    process_signal(data, len);
    for (int i = 0; i < len; i++) {
        printf("%d ", data[i]);
    }
    return 0;
}