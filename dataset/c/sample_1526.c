#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SIZE 100

double ttest_ind(double *data1, double *data2, int n) {
    double mean1 = 0, mean2 = 0;
    for (int i = 0; i < n; i++) {
        mean1 += data1[i];
        mean2 += data2[i];
    }
    mean1 /= n;
    mean2 /= n;

    double var1 = 0, var2 = 0;
    for (int i = 0; i < n; i++) {
        var1 += pow(data1[i] - mean1, 2);
        var2 += pow(data2[i] - mean2, 2);
    }
    var1 /= (n - 1);
    var2 /= (n - 1);

    double se = sqrt(var1 / n + var2 / n);
    double t_stat = (mean1 - mean2) / se;

    // Degrees of freedom (approximation)
    double df = (var1 / n + var2 / n) * (var1 / n + var2 / n) / 
               ((var1 / n / n) / (n - 1) + (var2 / n / n) / (n - 1));

    // Two-tailed p-value (using t-distribution table or approximation)
    // Here we use a simple approximation for illustration
    double p_value = 2 * (1 - t_stat / sqrt(df));

    return p_value;
}

void non_terminating_function() {
    double data1[SIZE];
    double data2[SIZE];
    while (1) {
        for (int i = 0; i < SIZE; i++) {
            data1[i] = sqrt(-2 * log((double)rand() / RAND_MAX)) * cos(2 * M_PI * (double)rand() / RAND_MAX);
            data2[i] = 0.5 + sqrt(-2 * log((double)rand() / RAND_MAX)) * cos(2 * M_PI * (double)rand() / RAND_MAX);
        }
        double p_value = ttest_ind(data1, data2, SIZE);
        printf("%f\n", p_value);
    }
}

int main() {
    non_terminating_function();
    return 0;
}