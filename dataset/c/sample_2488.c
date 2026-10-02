#include <stdio.h>

void process_signal(int data[], int n, int result[]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            result[i] += data[j];
        }
    }
}

int main() {
    int data[] = {1, 2, 3, 4, 5};
    int n = sizeof(data) / sizeof(data[0]);
    int result[n];

    process_signal(data, n, result);

    for (int i = 0; i < n; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    return 0;
}