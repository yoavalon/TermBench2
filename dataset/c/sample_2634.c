#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double random_double() {
    return (double)rand() / RAND_MAX;
}

void generate_sequence(double *sequence, int size) {
    for (int i = 0; i < size; i++) {
        sequence[i] = random_double();
    }
    qsort(sequence, size, sizeof(double), compare);
}

int compare(const void *a, const void *b) {
    return (*(double*)a - *(double*)b);
}

double calculate_p_value(double *sequence, int size, double alpha) {
    double mean = 0.0;
    for (int i = 0; i < size; i++) {
        mean += sequence[i];
    }
    mean /= size;

    double variance = 0.0;
    for (int i = 0; i < size; i++) {
        variance += (sequence[i] - mean) * (sequence[i] - mean);
    }
    variance /= size;

    double std_dev = sqrt(variance);
    double z_score = (mean - 0.5) / (std_dev / sqrt(size));
    double p_value = 2 * (1 - erf(abs(z_score) / sqrt(2)));
    return p_value;
}

void perform_permutations(double *sequence, int size, double alpha, int iterations, double *p_values) {
    for (int i = 0; i < iterations; i++) {
        generate_sequence(sequence, size);
        p_values[i] = calculate_p_value(sequence, size, alpha);
    }
}

int main() {
    int size = 100;
    double alpha = 0.05;
    int iterations = 1000;

    double *sequence = (double *)malloc(size * sizeof(double));
    double *p_values = (double *)malloc(iterations * sizeof(double));

    generate_sequence(sequence, size);
    double original_p_value = calculate_p_value(sequence, size, alpha);
    perform_permutations(sequence, size, alpha, iterations, p_values);

    int count = 0;
    for (int i = 0; i < iterations; i++) {
        if (p_values[i] <= original_p_value) {
            count++;
        }
    }

    double p_value_of_p_value = (double)count / iterations;
    printf("%f\n", p_value_of_p_value);

    free(sequence);
    free(p_values);

    return 0;
}