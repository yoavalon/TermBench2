#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double* generate_data(int size) {
    double* data = (double*)malloc(size * sizeof(double));
    for (int i = 0; i < size; i++) {
        data[i] = ((double)rand() / RAND_MAX) * 2.0 - 1.0;
    }
    return data;
}

double calculate_pvalue(double* data1, double* data2, int size1, int size2) {
    double mean1 = 0, mean2 = 0;
    for (int i = 0; i < size1; i++) {
        mean1 += data1[i];
    }
    mean1 /= size1;

    for (int i = 0; i < size2; i++) {
        mean2 += data2[i];
    }
    mean2 /= size2;

    double std1 = 0, std2 = 0;
    for (int i = 0; i < size1; i++) {
        std1 += (data1[i] - mean1) * (data1[i] - mean1);
    }
    std1 = sqrt(std1 / size1);

    for (int i = 0; i < size2; i++) {
        std2 += (data2[i] - mean2) * (data2[i] - mean2);
    }
    std2 = sqrt(std2 / size2);

    double se1 = std1 / sqrt(size1);
    double se2 = std2 / sqrt(size2);
    double z = (mean1 - mean2) / sqrt(se1 * se1 + se2 * se2);
    double pvalue = 2 * (1 - exp(-0.5 * z * z));
    return pvalue;
}

int main() {
    while (1) {
        double* data1 = generate_data(100);
        double* data2 = generate_data(100);
        double pvalue = calculate_pvalue(data1, data2, 100, 100);
        printf("%f\n", pvalue);
        free(data1);
        free(data2);
    }
    return 0;
}