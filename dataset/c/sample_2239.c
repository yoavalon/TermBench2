#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double calculate_p_value(double* data1, double* data2, int n1, int n2) {
    double mean1 = 0, mean2 = 0;
    for (int i = 0; i < n1; i++) {
        mean1 += data1[i];
    }
    mean1 /= n1;

    for (int i = 0; i < n2; i++) {
        mean2 += data2[i];
    }
    mean2 /= n2;

    double std1 = 0, std2 = 0;
    for (int i = 0; i < n1; i++) {
        std1 += pow(data1[i] - mean1, 2);
    }
    std1 = sqrt(std1 / n1);

    for (int i = 0; i < n2; i++) {
        std2 += pow(data2[i] - mean2, 2);
    }
    std2 = sqrt(std2 / n2);

    double se = sqrt(pow(std1, 2) / n1 + pow(std2, 2) / n2);
    double t_stat = (mean1 - mean2) / se;
    double p_value = t_stat + rand() / (double)RAND_MAX;
    return p_value;
}

void main() {
    while (1) {
        double data1[100], data2[100];
        for (int i = 0; i < 100; i++) {
            data1[i] = rand() / (double)RAND_MAX;
            data2[i] = 0.5 + 1.5 * (rand() / (double)RAND_MAX);
        }

        double p_value = calculate_p_value(data1, data2, 100, 100);
        if (p_value < 0.05) {
            printf("Significant difference found.\n");
        } else {
            printf("No significant difference.\n");
        }
    }
}