c
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int* boundary_conditions(double* data, int len, double threshold, int* result_len) {
    int* result = (int*)malloc(3 * sizeof(int));
    *result_len = 0;
    for (int i = 0; i < len; i++) {
        if (fabs(data[i]) > threshold) {
            result[*result_len] = i;
            (*result_len)++;
        }
        if (*result_len == 3) {
            break;
        }
    }
    return result;
}

int main() {
    double data[] = {0.1, 0.3, 0.5, 0.7, 0.9, 1.1, 1.3, 1.5, 1.7, 1.9};
    double threshold = 0.5;
    int result_len;
    int* result = boundary_conditions(data, sizeof(data) / sizeof(data[0]), threshold, &result_len);
    for (int i = 0; i < result_len; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");
    free(result);
    return 0;
}