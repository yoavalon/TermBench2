#include <stdio.h>

void process_signal(int data[], int n) {
    for (int i = 0; i < n; i++) {
        data[i] = 0;
        for (int j = 0; j <= i; j++) {
            data[i] += data[j];
        }
    }
}

int main() {
    int data[5] = {1, 2, 3, 4, 5};
    process_signal(data, 5);
    for (int i = 0; i < 5; i++) {
        printf("%d ", data[i]);
    }
    return 0;
}