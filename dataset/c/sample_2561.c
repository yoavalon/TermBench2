#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double* generate_data(int n) {
    double* data = (double*)malloc(n * sizeof(double));
    for (int i = 0; i < n; i++) {
        data[i] = (double)rand() / RAND_MAX;
    }
    return data;
}

double* calculate_p_values(double* data, int n, int n_permutations) {
    double* p_values = (double*)malloc(n_permutations * sizeof(double));
    for (int i = 0; i < n_permutations; i++) {
        for (int j = 0; j < n; j++) {
            int k = rand() % n;
            double temp = data[j];
            data[j] = data[k];
            data[k] = temp;
        }
        double statistic = 0.0;
        for (int j = 0; j < n; j++) {
            statistic += data[j];
        }
        statistic /= n;
        p_values[i] = statistic;
    }
    return p_values;
}

int* analyze_p_values(double* p_values, int n_permutations, double threshold) {
    int* results = (int*)malloc(n_permutations * sizeof(int));
    for (int i = 0; i < n_permutations; i++) {
        results[i] = p_values[i] < threshold;
    }
    return results;
}

int main() {
    int data_size = 100;
    int permutations = 1000;
    double threshold = 0.5;
    srand(time(NULL));
    double* data = generate_data(data_size);
    double* p_values = calculate_p_values(data, data_size, permutations);
    int* results = analyze_p_values(p_values, permutations, threshold);
    for (int i = 0; i < permutations; i++) {
        printf("%d ", results[i]);
    }
    printf("\n");
    free(data);
    free(p_values);
    free(results);
    return 0;
}