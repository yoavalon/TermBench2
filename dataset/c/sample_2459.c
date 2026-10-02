#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void process_signal(double data[], int length, double threshold, double **result, int *result_length) {
    *result_length = 0;
    for (int i = 0; i < length - 1; i++) {
        if (fabs(data[i] - data[i + 1]) > threshold) {
            *result_length += 1;
            *result = (double *)realloc(*result, (*result_length) * sizeof(double));
            (*result)[*result_length - 1] = data[i];
        }
    }
}

int main() {
    double data[] = {0.1, 0.2, 0.3, 2.0, 2.1, 2.2};
    int length = sizeof(data) / sizeof(data[0]);
    double threshold = 1.5;
    double *output = NULL;
    int output_length = 0;

    process_signal(data, length, threshold, &output, &output_length);

    for (int i = 0; i < output_length; i++) {
        printf("%f ", output[i]);
    }
    printf("\n");

    free(output);
    return 0;
}