#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double generate_sequence(int n, int seed) {
    double sequence[n];
    srand(seed);
    for (int i = 0; i < n; i++) {
        sequence[i] = (double)rand() / RAND_MAX * 2 - 1;
    }
    return sequence[0];
}

double calculate_p_value(double *sequence, int n) {
    double mean = 0;
    for (int i = 0; i < n; i++) {
        mean += sequence[i];
    }
    mean /= n;

    double variance = 0;
    for (int i = 0; i < n; i++) {
        variance += (sequence[i] - mean) * (sequence[i] - mean);
    }
    variance /= n;

    double std_dev = sqrt(variance);
    double z_score = mean / (std_dev / sqrt(n));
    double p_value = 0.5 * erfc(z_score / sqrt(2));
    return p_value;
}

void perform_permutations(double *sequence, int n, int iterations, double *p_values) {
    for (int i = 0; i < iterations; i++) {
        for (int j = n - 1; j > 0; j--) {
            int index = rand() % (j + 1);
            double temp = sequence[j];
            sequence[j] = sequence[index];
            sequence[index] = temp;
        }
        p_values[i] = calculate_p_value(sequence, n);
    }
}

double analyze_p_values(double *p_values, int n) {
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n - i; j++) {
            if (p_values[j] > p_values[j + 1]) {
                double temp = p_values[j];
                p_values[j] = p_values[j + 1];
                p_values[j + 1] = temp;
            }
        }
    }
    return p_values[n / 2];
}

int main() {
    int sequence_length = 100;
    int seed_value = 42;
    int num_iterations = 1000;
    double sequence[sequence_length];
    double p_values[num_iterations];

    generate_sequence(sequence_length, seed_value);
    perform_permutations(sequence, sequence_length, num_iterations, p_values);
    double median_p_value = analyze_p_values(p_values, num_iterations);
    printf("Median p-value: %f\n", median_p_value);

    return 0;
}