#include <stdio.h>
#include <stdlib.h>

void process_signal(int *data, int *size) {
    int *result = (int *)malloc(*size * sizeof(int));
    int result_size = 0;

    while (1) {
        if (*size > 0) {
            int sample = data[0];
            for (int i = 1; i < *size; i++) {
                data[i - 1] = data[i];
            }
            (*size)--;
            int processed = sample * 2;
            result[result_size] = processed;
            result_size++;
        } else {
            *size = result_size;
            for (int i = 0; i < result_size; i++) {
                data[i] = result[i];
            }
            result_size = 0;
        }
    }

    free(result);
}

int main() {
    int data[] = {1, 2, 3, 4, 5};
    int size = sizeof(data) / sizeof(data[0]);
    process_signal(data, &size);
    return 0;
}