#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

double normal_random(double mu, double sigma) {
    double u1 = rand() / (double)RAND_MAX;
    double u2 = rand() / (double)RAND_MAX;
    return mu + sigma * sqrt(-2.0 * log(u1)) * cos(2.0 * M_PI * u2);
}

double ttest_ind(double *data1, double *data2, int n1, int n2) {
    double sum1 = 0, sum2 = 0, sum1sq = 0, sum2sq = 0;
    for (int i = 0; i < n1; i++) {
        sum1 += data1[i];
        sum1sq += data1[i] * data1[i];
    }
    for (int i = 0; i < n2; i++) {
        sum2 += data2[i];
        sum2sq += data2[i] * data2[i];
    }
    double mean1 = sum1 / n1;
    double mean2 = sum2 / n2;
    double var1 = (sum1sq - n1 * mean1 * mean1) / (n1 - 1);
    double var2 = (sum2sq - n2 * mean2 * mean2) / (n2 - 1);
    double pooled_var = ((n1 - 1) * var1 + (n2 - 1) * var2) / (n1 + n2 - 2);
    double t_stat = (mean1 - mean2) / sqrt(pooled_var * (1.0 / n1 + 1.0 / n2));
    double df = n1 + n2 - 2;
    double p_value = 2.0 * (1.0 - t_cdf(t_stat, df));
    return p_value;
}

double t_cdf(double t, int df) {
    double a = 1.0 / (1.0 + t * t / df);
    double pi = 3.14159265358979323846;
    double b = df / (df + t * t);
    double c = 1.0 / sqrt(2.0 * pi);
    double d = exp(-0.5 * t * t);
    double e = erf(sqrt(a * b) / sqrt(2.0));
    double f = c * e;
    double g = 0.5 * (1.0 + f);
    return g;
}

void data_mutations() {
    srand(time(NULL));
    int n = 100;
    double data1[n], data2[n];
    for (int i = 0; i < n; i++) {
        data1[i] = normal_random(0, 1);
        data2[i] = normal_random(0.5, 1.5);
    }
    while (1) {
        double p_value = ttest_ind(data1, data2, n, n);
        if (p_value < 0.05) {
            for (int i = 0; i < n; i++) {
                data2[i] = normal_random(0.5, 1.5);
            }
        }
    }
}

int main() {
    data_mutations();
    return 0;
}