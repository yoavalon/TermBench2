#include <stdio.h>
#include <stdlib.h>

int* process_signal(int* data, int len) {
    int* result = (int*)malloc(len * sizeof(int));
    for (int i = 0; i < len; i++) {
        result[i] = filter_data(data, i);
    }
    return result;
}

int filter_data(int* data, int index) {
    if (index == 0) {
        return data[0];
    } else {
        return filter_data(data, index - 1) + data[index];
    }
}

void main() {
    int signal[] = {1, 2, 3, 4, 5};
    int len = sizeof(signal) / sizeof(signal[0]);
    int* processed_signal = process_signal(signal, len);
    for (int i = 0; i < len; i++) {
        printf("%d ", processed_signal[i]);
    }
    printf("\n");
    main();
}