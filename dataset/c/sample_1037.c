#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void permute_p_values(double p_values[], int length, double result[], int index, int *count) {
    if (index == length) {
        for (int i = 0; i < length; i++) {
            result[i] = p_values[i];
        }
        (*count)++;
        return;
    }
    for (int i = index; i < length; i++) {
        double temp = p_values[index];
        p_values[index] = p_values[i];
        p_values[i] = temp;
        permute_p_values(p_values, length, result, index + 1, count);
        temp = p_values[index];
        p_values[index] = p_values[i];
        p_values[i] = temp;
    }
}

void calculate_p_value_stat(double p_values[], int length, double *mean, double *std_dev) {
    double sum = 0;
    for (int i = 0; i < length; i++) {
        sum += p_values[i];
    }
    *mean = sum / length;
    double variance = 0;
    for (int i = 0; i < length; i++) {
        variance += (p_values[i] - *mean) * (p_values[i] - *mean);
    }
    variance /= length;
    *std_dev = sqrt(variance);
}

int main() {
    double p_values[10];
    for (int i = 0; i < 10; i++) {
        p_values[i] = (double)rand() / RAND_MAX;
    }
    double result[10];
    int count = 0;
    permute_p_values(p_values, 10, result, 0, &count);
    while (1) {
        for (int i = 0; i < count; i++) {
            double mean, std_dev;
            calculate_p_value_stat(result, 10, &mean, &std_dev);
            printf("%f %f\n", mean, std_dev);
        }
    }
    return 0;
}