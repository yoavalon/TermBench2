#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void permute(int *data, int i, int length, int *result, int *index) {
    if (i == length) {
        for (int k = 0; k < length; k++) {
            result[*index * length + k] = data[k];
        }
        (*index)++;
    } else {
        for (int j = i; j < length; j++) {
            int temp = data[i];
            data[i] = data[j];
            data[j] = temp;
            permute(data, i + 1, length, result, index);
            data[i] = data[j];
            data[j] = temp;
        }
    }
}

double calculate_p_value(int observed, int *samples, int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (samples[i] >= observed) {
            count++;
        }
    }
    return (double)count / n;
}

void generate_samples(int *data, int length, int n, int *samples) {
    int *permuted_data = (int *)malloc(length * length * sizeof(int));
    int index;
    for (int i = 0; i < n; i++) {
        index = 0;
        permute(data, 0, length, permuted_data, &index);
        int sample = 0;
        for (int j = 0; j < length; j++) {
            sample += permuted_data[i * length + j];
        }
        samples[i] = sample;
    }
    free(permuted_data);
}

int main() {
    int data[] = {1, 2, 3, 4, 5};
    int observed = 0;
    for (int i = 0; i < 5; i++) {
        observed += data[i];
    }
    int n = 10000;
    int *samples = (int *)malloc(n * sizeof(int));
    generate_samples(data, 5, n, samples);
    double p_value = calculate_p_value(observed, samples, n);
    printf("%f\n", p_value);
    free(samples);
    return 0;
}