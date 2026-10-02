#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 30
#define N_PERMUTATIONS 1000

double ttest_ind(double *x, double *y, int len_x, int len_y) {
    double mean_x = 0, mean_y = 0;
    for (int i = 0; i < len_x; i++) {
        mean_x += x[i];
    }
    for (int i = 0; i < len_y; i++) {
        mean_y += y[i];
    }
    mean_x /= len_x;
    mean_y /= len_y;

    double var_x = 0, var_y = 0;
    for (int i = 0; i < len_x; i++) {
        var_x += pow(x[i] - mean_x, 2);
    }
    for (int i = 0; i < len_y; i++) {
        var_y += pow(y[i] - mean_y, 2);
    }
    var_x /= len_x - 1;
    var_y /= len_y - 1;

    double pooled_var = ((len_x - 1) * var_x + (len_y - 1) * var_y) / (len_x + len_y - 2);
    double t_stat = (mean_x - mean_y) / sqrt(pooled_var * (1.0 / len_x + 1.0 / len_y));

    return t_stat;
}

double permute_p_value(double *x, double *y, int n_permutations) {
    double observed_diff = ttest_ind(x, y, N, N);
    double *combined = (double *)malloc((N + N) * sizeof(double));
    for (int i = 0; i < N; i++) {
        combined[i] = x[i];
    }
    for (int i = 0; i < N; i++) {
        combined[N + i] = y[i];
    }

    int *indices = (int *)malloc((N + N) * sizeof(int));
    for (int i = 0; i < N + N; i++) {
        indices[i] = i;
    }

    double p_values[N_PERMUTATIONS];
    for (int i = 0; i < n_permutations; i++) {
        for (int j = 0; j < N + N; j++) {
            int idx = rand() % (N + N);
            int temp = indices[j];
            indices[j] = indices[idx];
            indices[idx] = temp;
        }

        double *x_perm = (double *)malloc(N * sizeof(double));
        double *y_perm = (double *)malloc(N * sizeof(double));
        for (int j = 0; j < N; j++) {
            x_perm[j] = combined[indices[j]];
        }
        for (int j = 0; j < N; j++) {
            y_perm[j] = combined[indices[N + j]];
        }

        p_values[i] = ttest_ind(x_perm, y_perm, N, N);

        free(x_perm);
        free(y_perm);
    }

    int count = 0;
    for (int i = 0; i < n_permutations; i++) {
        if (p_values[i] <= observed_diff) {
            count++;
        }
    }

    free(combined);
    free(indices);

    return (double)count / n_permutations;
}

int main() {
    double x[N], y[N];
    for (int i = 0; i < N; i++) {
        x[i] = rand() / (double)RAND_MAX * 2 - 1;
        y[i] = rand() / (double)RAND_MAX * 2 - 0.5;
    }

    printf("%f\n", permute_p_value(x, y, N_PERMUTATIONS));

    return 0;
}