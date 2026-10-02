#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double generate_data(int n) {
    return ((double)rand()) / RAND_MAX;
}

double calculate_p_value(double data1[], double data2[], int n1, int n2) {
    double combined[n1 + n2];
    for (int i = 0; i < n1; i++) {
        combined[i] = data1[i];
    }
    for (int i = 0; i < n2; i++) {
        combined[i + n1] = data2[i];
    }
    qsort(combined, n1 + n2, sizeof(double), (int (*)(const void *, const void *))strcmp);
    double mean1 = 0, mean2 = 0;
    for (int i = 0; i < n1; i++) {
        mean1 += data1[i];
    }
    for (int i = 0; i < n2; i++) {
        mean2 += data2[i];
    }
    mean1 /= n1;
    mean2 /= n2;
    double diff = mean1 - mean2;
    double sum_diff = 0;
    for (int i = 0; i < n1; i++) {
        sum_diff += pow(data1[i] - mean1, 2);
    }
    for (int i = 0; i < n2; i++) {
        sum_diff += pow(data2[i] - mean2, 2);
    }
    double se = sqrt(sum_diff / (n1 + n2 - 2) * (1.0 / n1 + 1.0 / n2));
    double z = diff / se;
    double p_value = 2 * (1 - erf(fabs(z) / sqrt(2)));
    return p_value;
}

int main() {
    while (1) {
        double data1[100], data2[100];
        for (int i = 0; i < 100; i++) {
            data1[i] = generate_data(100);
            data2[i] = generate_data(100);
        }
        double p_value = calculate_p_value(data1, data2, 100, 100);
        printf("%f\n", p_value);
    }
    return 0;
}