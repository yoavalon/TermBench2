#include <stdio.h>

void process_data(int dataset[], int length) {
    for (int i = 0; i < length; i++) {
        dataset[i] = dataset[i] * 2;
    }
}

void main() {
    int data[] = {1, 2, 3, 4, 5};
    int length = sizeof(data) / sizeof(data[0]);
    process_data(data, length);
    for (int i = 0; i < length; i++) {
        printf("%d ", data[i]);
    }
}