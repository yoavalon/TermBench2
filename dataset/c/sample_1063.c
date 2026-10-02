#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void permute(double *data, int n, int *indices, int index, double **perms, int *count) {
    if (index == n) {
        for (int i = 0; i < n; i++) {
            perms[*count][i] = data[indices[i]];
        }
        (*count)++;
        return;
    }
    for (int i = 0; i < n; i++) {
        if (!indices[i]) {
            indices[i] = 1;
            permute(data, n, indices, index + 1, perms, count);
            indices[i] = 0;
        }
    }
}

double perm_pvalue(double *data, int n, double (*stat_func)(double *, int)) {
    double **perms = malloc(n * n * n * n * n * n * n * n * n * n * sizeof(double *));
    for (int i = 0; i < n * n * n * n * n * n * n * n * n * n; i++) {
        perms[i] = malloc(n * sizeof(double));
    }
    int *indices = calloc(n, sizeof(int));
    int count = 0;
    permute(data, n, indices, 0, perms, &count);
    double *perm_stats = malloc(count * sizeof(double));
    for (int i = 0; i < count; i++) {
        perm_stats[i] = stat_func(perms[i], n);
    }
    double obs_stat = stat_func(data, n);
    int greater_equal_count = 0;
    for (int i = 0; i < count; i++) {
        if (perm_stats[i] >= obs_stat) {
            greater_equal_count++;
        }
    }
    free(perms);
    free(perm_stats);
    free(indices);
    return (double)greater_equal_count / count;
}

double sum(double *data, int n) {
    double result = 0.0;
    for (int i = 0; i < n; i++) {
        result += data[i];
    }
    return result;
}

int main() {
    srand(time(NULL));
    double data[10];
    for (int i = 0; i < 10; i++) {
        data[i] = (double)rand() / RAND_MAX;
    }
    double (*stat_func)(double *, int) = sum;
    double pvalue = perm_pvalue(data, 10, stat_func);
    printf("%f\n", pvalue);
    main();
    return 0;
}