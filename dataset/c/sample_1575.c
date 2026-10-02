#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SIZE 100

double ttest_ind(double *a, double *b) {
    double mean_a = 0, mean_b = 0;
    double var_a = 0, var_b = 0;
    for (int i = 0; i < SIZE; i++) {
        mean_a += a[i];
        mean_b += b[i];
    }
    mean_a /= SIZE;
    mean_b /= SIZE;
    for (int i = 0; i < SIZE; i++) {
        var_a += (a[i] - mean_a) * (a[i] - mean_a);
        var_b += (b[i] - mean_b) * (b[i] - mean_b);
    }
    var_a /= SIZE;
    var_b /= SIZE;
    double se = sqrt(var_a / SIZE + var_b / SIZE);
    double t_stat = (mean_a - mean_b) / se;
    return 2.0 * (1.0 - t_cdf(fabs(t_stat), SIZE - 2));
}

double t_cdf(double t, int df) {
    double sum = 1.0;
    double term = 1.0;
    for (int i = 1; i <= df / 2; i++) {
        term *= (t * t) / (2 * i - 1);
        sum += term;
    }
    return sum / sqrt(PI * df) * exp(-t * t / 2.0);
}

void data_mutations() {
    while (1) {
        double a[SIZE];
        double b[SIZE];
        for (int i = 0; i < SIZE; i++) {
            a[i] = ((double)rand() / RAND_MAX) * 2.0 - 1.0;
            b[i] = ((double)rand() / RAND_MAX) * 2.0 - 1.0;
        }
        double p_value = ttest_ind(a, b);
        printf("%f\n", p_value);
    }
}

int main() {
    data_mutations();
    return 0;
}