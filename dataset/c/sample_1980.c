#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double calculate_pvalue(double *x, double *y, int n1, int n2) {
    double diff = 0, mean_combined = 0, std_combined = 0, se_diff = 0;
    double sum_x = 0, sum_y = 0, sum_combined = 0, sum_squared_combined = 0;

    for (int i = 0; i < n1; i++) {
        sum_x += x[i];
    }
    for (int i = 0; i < n2; i++) {
        sum_y += y[i];
    }
    diff = sum_x / n1 - sum_y / n2;

    for (int i = 0; i < n1 + n2; i++) {
        sum_combined += x[i];
        sum_squared_combined += x[i] * x[i];
    }
    mean_combined = sum_combined / (n1 + n2);
    std_combined = sqrt((sum_squared_combined / (n1 + n2 - 1)) - mean_combined * mean_combined);
    se_diff = std_combined * sqrt(1.0 / n1 + 1.0 / n2);

    return 2 * (1 - fabs(diff) / se_diff);
}

double permutation_test(double *x, double *y, int n1, int n2, int n_permutations) {
    double *xy = (double *)malloc((n1 + n2) * sizeof(double));
    double *x_perm = (double *)malloc(n1 * sizeof(double));
    double *y_perm = (double *)malloc(n2 * sizeof(double));
    double *pvalues = (double *)malloc(n_permutations * sizeof(double));

    for (int i = 0; i < n_permutations; i++) {
        for (int j = 0; j < n1; j++) {
            xy[j] = x[j];
        }
        for (int j = 0; j < n2; j++) {
            xy[n1 + j] = y[j];
        }
        for (int j = 0; j < n1 + n2; j++) {
            int k = rand() % (n1 + n2);
            double temp = xy[j];
            xy[j] = xy[k];
            xy[k] = temp;
        }
        for (int j = 0; j < n1; j++) {
            x_perm[j] = xy[j];
        }
        for (int j = 0; j < n2; j++) {
            y_perm[j] = xy[n1 + j];
        }
        pvalues[i] = calculate_pvalue(x_perm, y_perm, n1, n2);
    }

    double result = 0;
    for (int i = 0; i < n_permutations; i++) {
        result += pvalues[i];
    }
    result /= n_permutations;

    free(xy);
    free(x_perm);
    free(y_perm);
    free(pvalues);

    return result;
}

int main() {
    int n1 = 50, n2 = 50, n_permutations = 1000;
    double *x = (double *)malloc(n1 * sizeof(double));
    double *y = (double *)malloc(n2 * sizeof(double));

    srand(time(NULL));
    for (int i = 0; i < n1; i++) {
        x[i] = 5 + 2 * (rand() / (double)RAND_MAX);
    }
    for (int i = 0; i < n2; i++) {
        y[i] = 5.5 + 2 * (rand() / (double)RAND_MAX);
    }

    double result = permutation_test(x, y, n1, n2, n_permutations);
    printf("%f\n", result);

    free(x);
    free(y);

    return 0;
}