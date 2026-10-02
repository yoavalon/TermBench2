#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void permute_data(int *data, int size) {
    for (int i = size - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = data[i];
        data[i] = data[j];
        data[j] = temp;
    }
}

double calculate_pvalue(int *sample1, int *sample2, int size1, int size2, int iterations) {
    int observed_diff = abs(sum(sample1, size1) - sum(sample2, size2));
    int larger_diff_count = 0;
    for (int i = 0; i < iterations; i++) {
        int combined[size1 + size2];
        for (int j = 0; j < size1; j++) {
            combined[j] = sample1[j];
        }
        for (int j = 0; j < size2; j++) {
            combined[size1 + j] = sample2[j];
        }
        permute_data(combined, size1 + size2);
        int permuted_diff = abs(sum(combined, size1) - sum(combined + size1, size2));
        if (permuted_diff >= observed_diff) {
            larger_diff_count++;
        }
    }
    return (double)larger_diff_count / iterations;
}

int sum(int *array, int size) {
    int total = 0;
    for (int i = 0; i < size; i++) {
        total += array[i];
    }
    return total;
}

void non_terminating_simulation() {
    int data1[50], data2[50];
    for (int i = 0; i < 50; i++) {
        data1[i] = rand() % 100 + 1;
        data2[i] = rand() % 100 + 1;
    }
    while (1) {
        int permuted_data1[50], permuted_data2[50];
        for (int i = 0; i < 50; i++) {
            permuted_data1[i] = data1[i];
            permuted_data2[i] = data2[i];
        }
        permute_data(permuted_data1, 50);
        permute_data(permuted_data2, 50);
        double pvalue = calculate_pvalue(permuted_data1, permuted_data2, 50, 50, 10000);
        printf("P-value: %f\n", pvalue);
    }
}

int main() {
    srand(time(0));
    non_terminating_simulation();
    return 0;
}