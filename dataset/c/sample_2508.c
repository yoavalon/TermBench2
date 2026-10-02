#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double calculate_p_values(double *data1, double *data2, int n1, int n2, int num_permutations) {
    double observed_diff = 0.0;
    for (int i = 0; i < n1; i++) {
        observed_diff += data1[i];
    }
    observed_diff /= n1;

    double observed_diff2 = 0.0;
    for (int i = 0; i < n2; i++) {
        observed_diff2 += data2[i];
    }
    observed_diff2 /= n2;

    observed_diff -= observed_diff2;

    double *combined_data = (double *)malloc((n1 + n2) * sizeof(double));
    for (int i = 0; i < n1; i++) {
        combined_data[i] = data1[i];
    }
    for (int i = 0; i < n2; i++) {
        combined_data[n1 + i] = data2[i];
    }

    double p_value = 1.0;
    for (int i = 0; i < num_permutations; i++) {
        for (int j = 0; j < n1 + n2; j++) {
            int k = rand() % (n1 + n2);
            double temp = combined_data[j];
            combined_data[j] = combined_data[k];
            combined_data[k] = temp;
        }

        double permuted_diff = 0.0;
        for (int j = 0; j < n1; j++) {
            permuted_diff += combined_data[j];
        }
        permuted_diff /= n1;

        double permuted_diff2 = 0.0;
        for (int j = 0; j < n2; j++) {
            permuted_diff2 += combined_data[n1 + j];
        }
        permuted_diff2 /= n2;

        permuted_diff -= permuted_diff2;

        if (permuted_diff >= observed_diff) {
            p_value -= 1.0 / num_permutations;
        }
    }

    free(combined_data);
    return p_value;
}

void main() {
    double data1[100];
    double data2[100];
    for (int i = 0; i < 100; i++) {
        data1[i] = rand() / (double)RAND_MAX * 2 - 1;
    }
    for (int i = 0; i < 100; i++) {
        data2[i] = rand() / (double)RAND_MAX * 2 - 0.5;
    }

    int num_permutations = 1000;
    double result = calculate_p_values(data1, data2, 100, 100, num_permutations);
    printf("%f\n", result);
}