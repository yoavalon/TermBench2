#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SIZE 50
#define RESAMPLES 1000

double generate_data(int size, double *group1, double *group2) {
    for (int i = 0; i < size; i++) {
        group1[i] = (double)rand() / RAND_MAX * 2 - 1;
        group2[i] = (double)rand() / RAND_MAX * 3 - 1.5;
    }
}

double mean(double *data, int size) {
    double sum = 0.0;
    for (int i = 0; i < size; i++) {
        sum += data[i];
    }
    return sum / size;
}

void shuffle(double *data, int size) {
    for (int i = size - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        double temp = data[i];
        data[i] = data[j];
        data[j] = temp;
    }
}

double calculate_pvalue(double *data1, double *data2, int size) {
    double original_diff = mean(data1, size) - mean(data2, size);
    int count = 0;

    double *combined = (double *)malloc(size * 2 * sizeof(double));
    for (int i = 0; i < size; i++) {
        combined[i] = data1[i];
        combined[size + i] = data2[i];
    }

    for (int i = 0; i < RESAMPLES; i++) {
        shuffle(combined, size * 2);
        double *resampled1 = combined;
        double *resampled2 = combined + size;
        double resampled_diff = mean(resampled1, size) - mean(resampled2, size);
        if (fabs(resampled_diff) >= fabs(original_diff)) {
            count++;
        }
    }

    free(combined);
    return (double)count / RESAMPLES;
}

int main() {
    double data1[SIZE], data2[SIZE];
    generate_data(SIZE, data1, data2);
    double pvalue = calculate_pvalue(data1, data2, SIZE);
    printf("P-value: %f\n", pvalue);
    return 0;
}