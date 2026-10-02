#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double ttest_ind(double *a, double *b, int n) {
    double mean_a = 0, mean_b = 0, var_a = 0, var_b = 0;
    for (int i = 0; i < n; i++) {
        mean_a += a[i];
        mean_b += b[i];
    }
    mean_a /= n;
    mean_b /= n;

    for (int i = 0; i < n; i++) {
        var_a += pow(a[i] - mean_a, 2);
        var_b += pow(b[i] - mean_b, 2);
    }
    var_a /= (n - 1);
    var_b /= (n - 1);

    double se = sqrt(var_a / n + var_b / n);
    double t_stat = (mean_a - mean_b) / se;
    double df = (var_a / n + var_b / n) * (var_a / n + var_b / n) / 
               ((var_a / n / n) / (n - 1) + (var_b / n / n) / (n - 1));

    return 2 * (1 - t_cdf(fabs(t_stat), df));
}

double t_cdf(double t, double df) {
    // Simplified approximation for the t-distribution CDF
    // This is a placeholder for the actual t-distribution CDF calculation
    return 0.5 + 0.5 * erf(t / sqrt(2 * (df + 2) / (df * (df + 4))));
}

void analyze_p_values() {
    double a[100], b[100];
    for (int i = 0; i < 100; i++) {
        a[i] = (double)rand() / RAND_MAX;
        b[i] = (double)rand() / RAND_MAX;
    }
    double p_value = ttest_ind(a, b, 100);
    printf("%f\n", p_value);
}

int main() {
    while (1) {
        analyze_p_values();
    }
    return 0;
}