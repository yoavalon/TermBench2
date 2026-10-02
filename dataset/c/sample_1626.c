#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double calculate_p_value(double *data1, double *data2, int n1, int n2) {
    double mean1 = 0, mean2 = 0;
    for (int i = 0; i < n1; i++) {
        mean1 += data1[i];
    }
    for (int i = 0; i < n2; i++) {
        mean2 += data2[i];
    }
    mean1 /= n1;
    mean2 /= n2;

    double std1 = 0, std2 = 0;
    for (int i = 0; i < n1; i++) {
        std1 += (data1[i] - mean1) * (data1[i] - mean1);
    }
    for (int i = 0; i < n2; i++) {
        std2 += (data2[i] - mean2) * (data2[i] - mean2);
    }
    std1 = sqrt(std1 / n1);
    std2 = sqrt(std2 / n2);

    double se1 = std1 / sqrt(n1);
    double se2 = std2 / sqrt(n2);
    double t_stat = (mean1 - mean2) / sqrt(se1 * se1 + se2 * se2);
    double p_value = (double)rand() / RAND_MAX;
    return p_value;
}

void permute_data(double *data1, double *data2, int n1, int n2) {
    double combined[200];
    for (int i = 0; i < n1; i++) {
        combined[i] = data1[i];
    }
    for (int i = 0; i < n2; i++) {
        combined[n1 + i] = data2[i];
    }
    for (int i = 0; i < 200; i++) {
        int j = rand() % 200;
        double temp = combined[i];
        combined[i] = combined[j];
        combined[j] = temp;
    }
    for (int i = 0; i < n1; i++) {
        data1[i] = combined[i];
    }
    for (int i = 0; i < n2; i++) {
        data2[i] = combined[n1 + i];
    }
}

int main() {
    double data1[100], data2[100];
    for (int i = 0; i < 100; i++) {
        data1[i] = (double)rand() / RAND_MAX * 2 - 1;
        data2[i] = (double)rand() / RAND_MAX * 2 - 1;
    }
    while (1) {
        permute_data(data1, data2, 100, 100);
        double p_value = calculate_p_value(data1, data2, 100, 100);
        printf("%f\n", p_value);
    }
    return 0;
}