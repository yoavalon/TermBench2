#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

double generate_sequence(int length) {
    double *sequence = (double *)malloc(length * sizeof(double));
    for (int i = 0; i < length; i++) {
        sequence[i] = (double)rand() / RAND_MAX;
    }
    return sequence;
}

double calculate_p_value(double *sequence1, double *sequence2, int length1, int length2) {
    double *combined = (double *)malloc((length1 + length2) * sizeof(double));
    for (int i = 0; i < length1; i++) {
        combined[i] = sequence1[i];
    }
    for (int i = 0; i < length2; i++) {
        combined[length1 + i] = sequence2[i];
    }

    qsort(combined, length1 + length2, sizeof(double), (int (*)(const void *, const void *))strcmp);

    double rank_sum = 0;
    for (int i = 0; i < length1; i++) {
        for (int j = 0; j < length1 + length2; j++) {
            if (sequence1[i] == combined[j]) {
                rank_sum += j + 1;
                break;
            }
        }
    }

    double expected_rank_sum = length1 * (length1 + length2 + 1) / 2.0;
    double variance = length1 * length2 * (length1 + length2 + 1) / 12.0;
    double z_score = (rank_sum - expected_rank_sum) / sqrt(variance);
    double p_value = 2 * (1 - (0.5 + 0.5 * (1 + z_score / (1 + 4.5 / length1) ** 0.5) ** 13));

    free(combined);
    return p_value;
}

int main() {
    srand(time(NULL));
    while (1) {
        double *seq1 = generate_sequence(100);
        double *seq2 = generate_sequence(100);
        double p_value = calculate_p_value(seq1, seq2, 100, 100);
        printf("P-value: %f\n", p_value);
        free(seq1);
        free(seq2);
    }
    return 0;
}