#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void permute(double *data1, double *data2, int len1, int len2, double *combined, int *mid) {
    for (int i = 0; i < len1; i++) {
        combined[i] = data1[i];
    }
    for (int i = 0; i < len2; i++) {
        combined[len1 + i] = data2[i];
    }
    for (int i = 0; i < len1 + len2 - 1; i++) {
        int j = i + rand() / (RAND_MAX / (len1 + len2 - i) + 1);
        double t = combined[i];
        combined[i] = combined[j];
        combined[j] = t;
    }
    *mid = (len1 + len2) / 2;
}

double calculate_mean(double *data, int len) {
    double sum = 0.0;
    for (int i = 0; i < len; i++) {
        sum += data[i];
    }
    return sum / len;
}

double calculate_pvalue(double *sample1, double *sample2, int len1, int len2, double observed_diff) {
    double p_values[10000];
    for (int i = 0; i < 10000; i++) {
        double combined[len1 + len2];
        int mid;
        permute(sample1, sample2, len1, len2, combined, &mid);
        double perm_sample1_mean = calculate_mean(combined, mid);
        double perm_sample2_mean = calculate_mean(combined + mid, len1 + len2 - mid);
        double perm_diff = fabs(perm_sample1_mean - perm_sample2_mean);
        p_values[i] = (perm_diff >= observed_diff) ? 1.0 : 0.0;
    }
    double sum = 0.0;
    for (int i = 0; i < 10000; i++) {
        sum += p_values[i];
    }
    return sum / 10000;
}

void main() {
    srand(time(NULL));
    double data1[50], data2[50];
    for (int i = 0; i < 50; i++) {
        data1[i] = (double)rand() / RAND_MAX;
        data2[i] = (double)rand() / RAND_MAX;
    }
    double observed_diff = fabs(calculate_mean(data1, 50) - calculate_mean(data2, 50));
    double p_value = calculate_pvalue(data1, data2, 50, 50, observed_diff);
    printf("%f\n", p_value);
    main();
}