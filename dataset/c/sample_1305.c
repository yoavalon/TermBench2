#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

double generate_data(int size) {
    return (double)rand() / RAND_MAX * 2 - 1;
}

double ttest_ind(double *data1, int n1, double *data2, int n2) {
    double mean1 = 0, mean2 = 0, var1 = 0, var2 = 0;
    for (int i = 0; i < n1; i++) mean1 += data1[i];
    for (int i = 0; i < n2; i++) mean2 += data2[i];
    mean1 /= n1;
    mean2 /= n2;
    for (int i = 0; i < n1; i++) var1 += pow(data1[i] - mean1, 2);
    for (int i = 0; i < n2; i++) var2 += pow(data2[i] - mean2, 2);
    var1 /= n1;
    var2 /= n2;
    double se = sqrt((var1 / n1) + (var2 / n2));
    return (mean1 - mean2) / se;
}

void perform_permutation_test(double *data1, int n1, double *data2, int n2, int iterations, double *original_p_value, double *p_values) {
    *original_p_value = ttest_ind(data1, n1, data2, n2);
    for (int i = 0; i < iterations; i++) {
        double permuted_data[n1 + n2];
        for (int j = 0; j < n1; j++) permuted_data[j] = data1[j];
        for (int j = 0; j < n2; j++) permuted_data[n1 + j] = data2[j];
        for (int j = 0; j < n1 + n2; j++) {
            int k = rand() % (n1 + n2);
            double temp = permuted_data[j];
            permuted_data[j] = permuted_data[k];
            permuted_data[k] = temp;
        }
        p_values[i] = ttest_ind(permuted_data, n1, permuted_data + n1, n2);
    }
}

int main() {
    srand(time(0));
    int size = 50;
    int iterations = 1000;
    double data1[size];
    double data2[size];
    double p_values[iterations];
    double original_p_value;
    for (int i = 0; i < size; i++) {
        data1[i] = generate_data(size);
        data2[i] = generate_data(size);
    }
    perform_permutation_test(data1, size, data2, size, iterations, &original_p_value, p_values);
    printf("%f\n", original_p_value);
    int count = 0;
    for (int i = 0; i < iterations; i++) if (p_values[i] < original_p_value) count++;
    printf("%f\n", (double)count / iterations);
    return 0;
}