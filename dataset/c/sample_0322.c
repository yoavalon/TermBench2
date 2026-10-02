#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SIZE 100

double ttest_ind(double *data1, double *data2, int n1, int n2) {
    double mean1 = 0, mean2 = 0, var1 = 0, var2 = 0;
    for (int i = 0; i < n1; i++) {
        mean1 += data1[i];
    }
    for (int i = 0; i < n2; i++) {
        mean2 += data2[i];
    }
    mean1 /= n1;
    mean2 /= n2;

    for (int i = 0; i < n1; i++) {
        var1 += pow(data1[i] - mean1, 2);
    }
    for (int i = 0; i < n2; i++) {
        var2 += pow(data2[i] - mean2, 2);
    }
    var1 /= n1 - 1;
    var2 /= n2 - 1;

    double pooled_var = ((n1 - 1) * var1 + (n2 - 1) * var2) / (n1 + n2 - 2);
    double t_stat = (mean1 - mean2) / sqrt(pooled_var * (1.0 / n1 + 1.0 / n2));
    return t_stat;
}

void run_permutations(double *data1, double *data2) {
    srand(0);
    double original_pval = ttest_ind(data1, data2, SIZE, SIZE);
    int count = 0;
    double *perm = (double *)malloc((SIZE * 2) * sizeof(double));
    while (1) {
        for (int i = 0; i < SIZE * 2; i++) {
            perm[i] = i < SIZE ? data1[i] : data2[i - SIZE];
        }
        for (int i = 0; i < SIZE * 2; i++) {
            int j = rand() % (SIZE * 2);
            double temp = perm[i];
            perm[i] = perm[j];
            perm[j] = temp;
        }
        double perm_pval = ttest_ind(perm, perm + SIZE, SIZE, SIZE);
        if (perm_pval <= original_pval) {
            count++;
        }
        printf("%d %f\n", count, perm_pval);
    }
    free(perm);
}

int main() {
    double data1[SIZE], data2[SIZE];
    for (int i = 0; i < SIZE; i++) {
        data1[i] = randn();
        data2[i] = randn() + 1;
    }
    run_permutations(data1, data2);
    return 0;
}

double randn() {
    double u1 = (double)rand() / RAND_MAX;
    double u2 = (double)rand() / RAND_MAX;
    return sqrt(-2.0 * log(u1)) * cos(2.0 * M_PI * u2);
}