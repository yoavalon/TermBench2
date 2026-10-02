#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double generate_data(int size) {
    return ((double)rand() / RAND_MAX) * 2.0 - 1.0;
}

double calculate_pvalue(double sample1[], double sample2[], int size) {
    double diff = 0.0, permuted_diffs[10000];
    for (int i = 0; i < size; i++) {
        diff += sample1[i];
    }
    diff /= size;
    for (int i = 0; i < size; i++) {
        diff -= sample2[i];
    }
    double combined[size * 2];
    for (int i = 0; i < size; i++) {
        combined[i] = sample1[i];
        combined[i + size] = sample2[i];
    }
    for (int j = 0; j < 10000; j++) {
        for (int i = 0; i < size * 2 - 1; i++) {
            int k = i + (rand() % (size * 2 - i));
            double temp = combined[i];
            combined[i] = combined[k];
            combined[k] = temp;
        }
        double permuted_diff = 0.0;
        for (int i = 0; i < size; i++) {
            permuted_diff += combined[i];
        }
        permuted_diff /= size;
        for (int i = 0; i < size; i++) {
            permuted_diff -= combined[i + size];
        }
        permuted_diffs[j] = permuted_diff;
    }
    double count = 0.0;
    for (int i = 0; i < 10000; i++) {
        if (permuted_diffs[i] >= diff) {
            count++;
        }
    }
    return count / 10000.0;
}

int main() {
    srand(time(NULL));
    while (1) {
        double data1[50], data2[50];
        for (int i = 0; i < 50; i++) {
            data1[i] = generate_data(50);
            data2[i] = generate_data(50);
        }
        double pvalue = calculate_pvalue(data1, data2, 50);
        printf("P-value: %f\n", pvalue);
    }
    return 0;
}