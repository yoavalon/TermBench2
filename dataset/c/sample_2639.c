#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define SIZE 30
#define PERMUTATIONS 1000

typedef struct {
    int size;
} SequenceGenerator;

typedef struct {
    SequenceGenerator *generator;
} AnalysisRunner;

void SequenceGenerator_init(SequenceGenerator *self, int size) {
    self->size = size;
}

double* SequenceGenerator_generate(SequenceGenerator *self) {
    double *sequence = (double *)malloc(self->size * sizeof(double));
    for (int i = 0; i < self->size; i++) {
        sequence[i] = ((double)rand() / RAND_MAX);
    }
    return sequence;
}

double calculate_p_values(double *sequence1, double *sequence2, int size) {
    double observed_diff = 0, perm_diff;
    for (int i = 0; i < size; i++) {
        observed_diff += sequence1[i];
        observed_diff -= sequence2[i];
    }
    observed_diff /= size;

    double *combined = (double *)malloc(2 * size * sizeof(double));
    for (int i = 0; i < size; i++) {
        combined[i] = sequence1[i];
        combined[size + i] = sequence2[i];
    }

    double p_value = 0;
    for (int i = 0; i < PERMUTATIONS; i++) {
        for (int j = 0; j < 2 * size; j++) {
            int k = rand() % (2 * size);
            double temp = combined[j];
            combined[j] = combined[k];
            combined[k] = temp;
        }
        perm_diff = 0;
        for (int j = 0; j < size; j++) {
            perm_diff += combined[j] - combined[size + j];
        }
        perm_diff /= size;
        if (fabs(perm_diff) >= fabs(observed_diff)) {
            p_value += 1;
        }
    }
    free(combined);
    return p_value / PERMUTATIONS;
}

void AnalysisRunner_init(AnalysisRunner *self, SequenceGenerator *generator) {
    self->generator = generator;
}

double AnalysisRunner_run_analysis(AnalysisRunner *self) {
    double *seq1 = SequenceGenerator_generate(self->generator);
    double *seq2 = SequenceGenerator_generate(self->generator);
    double p_value = calculate_p_values(seq1, seq2, SIZE);
    free(seq1);
    free(seq2);
    return p_value;
}

int main() {
    srand(time(NULL));
    SequenceGenerator generator;
    SequenceGenerator_init(&generator, SIZE);
    AnalysisRunner runner;
    AnalysisRunner_init(&runner, &generator);
    double result = AnalysisRunner_run_analysis(&runner);
    printf("%f\n", result);
    return 0;
}