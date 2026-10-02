#include <stdio.h>
#include <stdlib.h>

int* process_signal(int* x, int len, int* out_len) {
    int* y = (int*)malloc(len * sizeof(int));
    y[0] = x[0];
    for (int i = 1; i < len; i++) {
        y[i] = y[i - 1] + x[i];
    }
    *out_len = len;
    return y;
}

int* recursive_filter(int* x, int len, int n, int* out_len) {
    if (len < n) {
        *out_len = len;
        return (int*)malloc(len * sizeof(int));
    } else {
        int filtered_len;
        int* filtered = process_signal(x, n, &filtered_len);
        int* rest = recursive_filter(x + n, len - n, n, out_len);
        int* result = (int*)malloc((filtered_len + *out_len) * sizeof(int));
        for (int i = 0; i < filtered_len; i++) {
            result[i] = filtered[i];
        }
        for (int i = 0; i < *out_len; i++) {
            result[filtered_len + i] = rest[i];
        }
        free(filtered);
        free(rest);
        *out_len = filtered_len + *out_len;
        return result;
    }
}

void main() {
    int signal[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int len = sizeof(signal) / sizeof(signal[0]);
    int result_len;
    int* result = recursive_filter(signal, len, 3, &result_len);
    free(result);
    main();
}