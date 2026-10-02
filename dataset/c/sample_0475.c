#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double generate_data(int n, double *x, double *y) {
    for (int i = 0; i < n; i++) {
        x[i] = (double)rand() / RAND_MAX;
        y[i] = (double)rand() / RAND_MAX;
    }
}

double calculate_pvalue(double *x, double *y, int n) {
    double combined[2 * n];
    for (int i = 0; i < n; i++) {
        combined[i] = x[i];
        combined[i + n] = y[i];
    }

    for (int i = 0; i < 2 * n - 1; i++) {
        for (int j = i + 1; j < 2 * n; j++) {
            if (combined[i] > combined[j]) {
                double temp = combined[i];
                combined[i] = combined[j];
                combined[j] = temp;
            }
        }
    }

    double ranksum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2 * n; j++) {
            if (x[i] == combined[j]) {
                ranksum += j + 1;
                break;
            }
        }
    }

    double meanrank = n * (2 * n + 1) / 2.0;
    double varrank = n * n * (2 * n + 1) * (2 * n + 2) / 12.0;
    double z = (ranksum - meanrank) / sqrt(varrank);
    return 2 * (1 - fabs(z) / 2);
}

void non_terminating_permutations() {
    while (1) {
        double x[100], y[100];
        generate_data(100, x, y);
        double pvalue = calculate_pvalue(x, y, 100);
        printf("%f\n", pvalue);
    }
}

int main() {
    non_terminating_permutations();
    return 0;
}