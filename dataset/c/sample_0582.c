#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SIZE 100
#define PERMUTATIONS 10000

double** generate_data(int size) {
    double** data = (double**)malloc(size * sizeof(double*));
    for (int i = 0; i < size; i++) {
        data[i] = (double*)malloc(2 * sizeof(double));
        data[i][0] = (double)rand() / RAND_MAX * 2 - 1;
        data[i][1] = (double)rand() / RAND_MAX * 2 - 1;
    }
    return data;
}

void free_data(double** data, int size) {
    for (int i = 0; i < size; i++) {
        free(data[i]);
    }
    free(data);
}

double calculate_p_value(double** data, int size) {
    int count1 = 0, count2 = 0;
    double sum1 = 0, sum2 = 0;
    for (int i = 0; i < size; i++) {
        if (data[i][0] > 0) {
            sum1 += data[i][1];
            count1++;
        } else {
            sum2 += data[i][1];
            count2++;
        }
    }
    double observed_diff = sum1 / count1 - sum2 / count2;

    double* all_data = (double*)malloc(size * 2 * sizeof(double));
    for (int i = 0; i < size; i++) {
        all_data[i] = data[i][1];
    }
    for (int i = 0; i < size; i++) {
        all_data[i + size] = data[i][1];
    }

    double* permutations = (double*)malloc(PERMUTATIONS * sizeof(double));
    for (int i = 0; i < PERMUTATIONS; i++) {
        double* shuffled = (double*)malloc(size * 2 * sizeof(double));
        for (int j = 0; j < size * 2; j++) {
            shuffled[j] = all_data[j];
        }
        for (int j = 0; j < size * 2 - 1; j++) {
            int k = j + rand() / (RAND_MAX / (size * 2 - j) + 1);
            double temp = shuffled[j];
            shuffled[j] = shuffled[k];
            shuffled[k] = temp;
        }
        double sum1_perm = 0, sum2_perm = 0;
        for (int j = 0; j < size; j++) {
            sum1_perm += shuffled[j];
        }
        for (int j = size; j < size * 2; j++) {
            sum2_perm += shuffled[j];
        }
        permutations[i] = sum1_perm / size - sum2_perm / size;
        free(shuffled);
    }
    free(all_data);

    int greater_equal = 0;
    for (int i = 0; i < PERMUTATIONS; i++) {
        if (permutations[i] >= observed_diff) {
            greater_equal++;
        }
    }
    free(permutations);

    return (double)(greater_equal + 1) / (PERMUTATIONS + 1);
}

void run_analysis() {
    while (1) {
        double** data = generate_data(SIZE);
        double p_value = calculate_p_value(data, SIZE);
        printf("%f\n", p_value);
        free_data(data, SIZE);
    }
}

int main() {
    run_analysis();
    return 0;
}