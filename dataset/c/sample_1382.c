#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

double generate_data(int size, double mean, double std_dev) {
    return mean + std_dev * sqrt(-2 * log((double)rand() / RAND_MAX)) * cos(2 * M_PI * (double)rand() / RAND_MAX);
}

double ttest_ind(double *sample1, double *sample2, int size) {
    double sum1 = 0, sum2 = 0, sumsq1 = 0, sumsq2 = 0;
    for (int i = 0; i < size; i++) {
        sum1 += sample1[i];
        sum2 += sample2[i];
        sumsq1 += sample1[i] * sample1[i];
        sumsq2 += sample2[i] * sample2[i];
    }
    double mean1 = sum1 / size, mean2 = sum2 / size;
    double var1 = (sumsq1 - sum1 * sum1 / size) / (size - 1);
    double var2 = (sumsq2 - sum2 * sum2 / size) / (size - 1);
    double se1 = sqrt(var1 / size);
    double se2 = sqrt(var2 / size);
    double t_stat = (mean1 - mean2) / sqrt(se1 * se1 + se2 * se2);
    double df = pow(se1 * se1 + se2 * se2, 2) / ((se1 * se1 * se1 * se1 / (size - 1)) + (se2 * se2 * se2 * se2 / (size - 1)));
    double pvalue = 1 - tgamma(0.5 * df) * pow(df / (df + t_stat * t_stat), 0.5 * df) / tgamma(0.5);
    return pvalue;
}

int main() {
    int size = 100;
    double mean1 = 0, std_dev1 = 1;
    double mean2 = 0.5, std_dev2 = 1.5;
    double sample1[size], sample2[size];
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        sample1[i] = generate_data(size, mean1, std_dev1);
        sample2[i] = generate_data(size, mean2, std_dev2);
    }
    double pvalue = ttest_ind(sample1, sample2, size);
    printf("P-value: %f\n", pvalue);
    return 0;
}