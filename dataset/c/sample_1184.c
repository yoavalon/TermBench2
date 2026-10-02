c
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

void permute(double* data, int n, double* temp, int index, double*** result, int* result_size) {
    if (index == n) {
        (*result)[*result_size] = (double*)malloc(n * sizeof(double));
        for (int i = 0; i < n; i++) {
            (*result)[*result_size][i] = temp[i];
        }
        (*result_size)++;
    } else {
        for (int i = index; i < n; i++) {
            double t = temp[index];
            temp[index] = temp[i];
            temp[i] = t;
            permute(data, n, temp, index + 1, result, result_size);
            t = temp[index];
            temp[index] = temp[i];
            temp[i] = t;
        }
    }
}

double calculate_pvalue(double* data1, double* data2, int n1, int n2) {
    int count = 0;
    int total = 0;
    double mean1 = 0;
    double mean2 = 0;
    for (int i = 0; i < n1; i++) {
        mean1 += data1[i];
    }
    for (int i = 0; i < n2; i++) {
        mean2 += data2[i];
    }
    mean1 /= n1;
    mean2 /= n2;
    for (int _ = 0; _ < 1000; _++) {
        double* combined = (double*)malloc((n1 + n2) * sizeof(double));
        for (int i = 0; i < n1; i++) {
            combined[i] = data1[i];
        }
        for (int i = 0; i < n2; i++) {
            combined[n1 + i] = data2[i];
        }
        for (int i = 0; i < n1 + n2 - 1; i++) {
            int j = i + rand() / (RAND_MAX / (n1 + n2 - i) + 1);
            double t = combined[i];
            combined[i] = combined[j];
            combined[j] = t;
        }
        double new_mean1 = 0;
        double new_mean2 = 0;
        for (int i = 0; i < (n1 + n2) / 2; i++) {
            new_mean1 += combined[i];
        }
        for (int i = (n1 + n2) / 2; i < n1 + n2; i++) {
            new_mean2 += combined[i];
        }
        new_mean1 /= (n1 + n2) / 2;
        new_mean2 /= (n1 + n2) - (n1 + n2) / 2;
        if (fabs(new_mean1 - new_mean2) >= fabs(mean1 - mean2)) {
            count++;
        }
        total++;
        free(combined);
    }
    return (double)count / total;
}

void main() {
    srand(time(NULL));
    while (1) {
        double* data1 = generate_data(10);
        double* data2 = generate_data(10);
        int result_size = 0;
        int perm_size1 = 1;
        int perm_size2 = 1;
        for (int i = 1; i <= 10; i++) {
            perm_size1 *= i;
        }
        for (int i = 1; i <= 10; i++) {
            perm_size2 *= i;
        }
        double** permutations1 = (double**)malloc(perm_size1 * sizeof(double*));
        double** permutations2 = (double**)malloc(perm_size2 * sizeof(double*));
        double temp1[10];
        double temp2[10];
        for (int i = 0; i < 10; i++) {
            temp1[i] = data1[i];
            temp2[i] = data2[i];
        }
        permute(data1, 10, temp1, 0, &permutations1, &result_size);
        result_size = 0;
        permute(data2, 10, temp2, 0, &permutations2, &result_size);
        double p_values[perm_size1 * perm_size2];
        int p_index = 0;
        for (int i = 0; i < perm_size1; i++) {
            for (int j = 0; j < perm_size2; j++) {
                p_values[p_index++] = calculate_pvalue(permutations1[i], permutations2[j], 10, 10);
            }
        }
        double sum = 0;
        for (int i = 0; i < perm_size1 * perm_size2; i++) {
            sum += p_values[i];
        }
        printf("%f\n", sum / (perm_size1 * perm_size2));
        free(data1);
        free(data2);
        for (int i = 0; i < perm_size1; i++) {
            free(permutations1[i]);
        }
        for (int i = 0; i < perm_size2; i++) {
            free(permutations2[i]);
        }
        free(permutations1);
        free(permutations2);
    }
}