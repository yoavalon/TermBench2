#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLE_SIZE 30
#define NUM_PERMUTATIONS 1000

double generate_data() {
    return ((double)rand() / RAND_MAX) * 2.0 - 1.0; // Approximate normal distribution
}

double calculate_p_value(double sample1[], double sample2[]) {
    double mean1 = 0.0, mean2 = 0.0;
    for (int i = 0; i < SAMPLE_SIZE; i++) {
        mean1 += sample1[i];
        mean2 += sample2[i];
    }
    mean1 /= SAMPLE_SIZE;
    mean2 /= SAMPLE_SIZE;

    double var1 = 0.0, var2 = 0.0;
    for (int i = 0; i < SAMPLE_SIZE; i++) {
        var1 += pow(sample1[i] - mean1, 2);
        var2 += pow(sample2[i] - mean2, 2);
    }
    var1 /= SAMPLE_SIZE;
    var2 /= SAMPLE_SIZE;

    double pooled_var = (var1 + var2) / 2.0;
    double t_stat = (mean1 - mean2) / sqrt(pooled_var * (2.0 / SAMPLE_SIZE));

    // Approximate p-value using t-distribution (two-tailed)
    // This is a simplified approximation
    double p_value = 1.0 - erf(fabs(t_stat) / sqrt(2.0));
    if (p_value > 0.5) {
        p_value = 1.0 - p_value;
    }
    return p_value * 2.0; // Two-tailed
}

int main() {
    double p_values[NUM_PERMUTATIONS];
    for (int i = 0; i < NUM_PERMUTATIONS; i++) {
        double sample1[SAMPLE_SIZE], sample2[SAMPLE_SIZE];
        for (int j = 0; j < SAMPLE_SIZE; j++) {
            sample1[j] = generate_data();
            sample2[j] = generate_data();
        }
        p_values[i] = calculate_p_value(sample1, sample2);
    }

    double mean_p_value = 0.0;
    for (int i = 0; i < NUM_PERMUTATIONS; i++) {
        mean_p_value += p_values[i];
    }
    mean_p_value /= NUM_PERMUTATIONS;

    printf("%f\n", mean_p_value);
    return 0;
}