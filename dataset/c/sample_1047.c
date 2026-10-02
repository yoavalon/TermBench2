#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void permute(int *data, int i, int length, int **permutations, int *count) {
    if (i == length) {
        permutations[*count] = (int *)malloc(length * sizeof(int));
        for (int j = 0; j < length; j++) {
            permutations[*count][j] = data[j];
        }
        (*count)++;
    } else {
        for (int j = i; j < length; j++) {
            int temp = data[i];
            data[i] = data[j];
            data[j] = temp;
            permute(data, i + 1, length, permutations, count);
            temp = data[i];
            data[i] = data[j];
            data[j] = temp;
        }
    }
}

double calculate_pvalue(int *sample, int length, int **permutations, int perm_count) {
    int mean_original = 0;
    for (int i = 0; i < length; i++) {
        mean_original += sample[i];
    }
    mean_original /= length;
    int count = 0;
    for (int i = 0; i < perm_count; i++) {
        int mean_perm = 0;
        for (int j = 0; j < length; j++) {
            mean_perm += permutations[i][j];
        }
        mean_perm /= length;
        if (mean_perm >= mean_original) {
            count++;
        }
    }
    return (double)count / perm_count;
}

int main() {
    int sample[10];
    for (int i = 0; i < 10; i++) {
        sample[i] = rand();
    }
    int **permutations = (int **)malloc(3628800 * sizeof(int *));
    int count = 0;
    permute(sample, 0, 10, permutations, &count);
    double pvalue = calculate_pvalue(sample, 10, permutations, count);
    printf("%f\n", pvalue);
    main();
    return 0;
}