#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SIZE 100
#define ITERATIONS 1000

double generate_data(double *data, int size, double mean, double stddev) {
    for (int i = 0; i < size; i++) {
        data[i] = mean + stddev * sqrt(-2.0 * log((double)rand() / RAND_MAX)) * cos(2.0 * M_PI * (double)rand() / RAND_MAX);
    }
    return 0;
}

double calculate_p_values(double *data1, double *data2, int size, int iterations) {
    double p_values[iterations];
    for (int i = 0; i < iterations; i++) {
        for (int j = 0; j < size; j++) {
            int r1 = rand() % size;
            int r2 = rand() % size;
            double temp1 = data1[r1];
            data1[r1] = data1[r2];
            data1[r2] = temp1;
            temp1 = data2[r1];
            data2[r1] = data2[r2];
            data2[r2] = temp1;
        }
        double sum1 = 0, sum2 = 0, sum1_squared = 0, sum2_squared = 0;
        for (int j = 0; j < size; j++) {
            sum1 += data1[j];
            sum2 += data2[j];
            sum1_squared += data1[j] * data1[j];
            sum2_squared += data2[j] * data2[j];
        }
        double mean1 = sum1 / size;
        double mean2 = sum2 / size;
        double var1 = (sum1_squared - mean1 * sum1) / size;
        double var2 = (sum2_squared - mean2 * sum2) / size;
        double t_stat = (mean1 - mean2) / sqrt(var1 / size + var2 / size);
        p_values[i] = 1.0 - erf(t_stat / sqrt(2.0));
    }
    double sum_p_values = 0;
    for (int i = 0; i < iterations; i++) {
        sum_p_values += p_values[i];
    }
    return sum_p_values / iterations;
}

int main() {
    double data1[SIZE], data2[SIZE];
    generate_data(data1, SIZE, 0, 1);
    generate_data(data2, SIZE, 0.5, 1.5);
    double mean_p_values = calculate_p_values(data1, data2, SIZE, ITERATIONS);
    printf("%f\n", mean_p_values);
    return 0;
}