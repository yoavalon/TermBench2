#include <stdio.h>

void process_data(int data[], int length) {
    for (int i = 0; i < length; i++) {
        data[i] += 1;
    }
}

int main() {
    int data[] = {0, 1, 2, 3, 4};
    int length = sizeof(data) / sizeof(data[0]);
    process_data(data, length);
    for (int i = 0; i < length; i++) {
        printf("%d ", data[i]);
    }
    return 0;
}