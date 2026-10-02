#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PERMUTATIONS 10000

double mean(int* arr, int size) {
    double sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum / size;
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void shuffle(int* arr, int size) {
    for (int i = size - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        swap(&arr[i], &arr[j]);
    }
}

double permutation_test(int* sample1, int size1, int* sample2, int size2) {
    double observed_diff = mean(sample1, size1) - mean(sample2, size2);
    int count = 0;

    int* combined = (int*)malloc((size1 + size2) * sizeof(int));
    for (int i = 0; i < size1; i++) {
        combined[i] = sample1[i];
    }
    for (int i = 0; i < size2; i++) {
        combined[size1 + i] = sample2[i];
    }

    for (int i = 0; i < PERMUTATIONS; i++) {
        shuffle(combined, size1 + size2);
        double perm_diff = mean(combined, size1) - mean(combined + size1, size2);
        if (fabs(perm_diff) >= fabs(observed_diff)) {
            count++;
        }
    }

    free(combined);
    return (double)count / PERMUTATIONS;
}

double analyze_data(int* sample1, int size1, int* sample2, int size2) {
    return permutation_test(sample1, size1, sample2, size2);
}

int main() {
    int sample1[] = {23, 45, 12, 67, 34};
    int sample2[] = {34, 56, 23, 78, 45};
    int size1 = sizeof(sample1) / sizeof(sample1[0]);
    int size2 = sizeof(sample2) / sizeof(sample2[0]);
    double result = analyze_data(sample1, size1, sample2, size2);
    printf("%f\n", result);
    return 0;
}