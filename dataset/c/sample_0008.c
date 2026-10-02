#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double permute_p_value(double *data1, double *data2, int n_permutations) {
    double observed_diff = 0.0, sum1 = 0.0, sum2 = 0.0;
    for (int i = 0; i < 50; i++) {
        sum1 += data1[i];
        sum2 += data2[i];
    }
    observed_diff = sum1 / 50 - sum2 / 50;

    double combined[100];
    for (int i = 0; i < 50; i++) {
        combined[i] = data1[i];
        combined[i + 50] = data2[i];
    }

    double permuted_diffs[n_permutations];
    for (int i = 0; i < n_permutations; i++) {
        for (int j = 0; j < 100; j++) {
            int k = rand() % 100;
            double temp = combined[j];
            combined[j] = combined[k];
            combined[k] = temp;
        }
        double sum1_perm = 0.0, sum2_perm = 0.0;
        for (int j = 0; j < 50; j++) {
            sum1_perm += combined[j];
            sum2_perm += combined[j + 50];
        }
        permuted_diffs[i] = sum1_perm / 50 - sum2_perm / 50;
    }

    int count = 0;
    for (int i = 0; i < n_permutations; i++) {
        if (permuted_diffs[i] >= observed_diff) {
            count++;
        }
    }
    double p_value = (count + 1.0) / (n_permutations + 1.0);
    return p_value;
}

int main() {
    srand(time(0));
    double data1[50], data2[50];
    for (int i = 0; i < 50; i++) {
        data1[i] = ((double)rand() / RAND_MAX) * 2 - 1;
        data2[i] = ((double)rand() / RAND_MAX) * 2 - 1;
    }

    double result = permute_p_value(data1, data2, 1000);
    printf("%f\n", result);
    return 0;
}