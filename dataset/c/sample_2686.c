#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define SIZE1 100
#define SIZE2 100
#define BOOTSTRAP_SAMPLES 1000

typedef struct {
    int size;
    double *data;
} SequenceGenerator;

typedef struct {
    double *sequence1;
    double *sequence2;
} PValueCalculator;

typedef struct {
    SequenceGenerator *sequence_generator1;
    SequenceGenerator *sequence_generator2;
} AnalysisRunner;

void SequenceGenerator_init(SequenceGenerator *self, int size) {
    self->size = size;
    self->data = (double *)malloc(size * sizeof(double));
    for (int i = 0; i < size; i++) {
        self->data[i] = (double)rand() / RAND_MAX;
    }
}

double *SequenceGenerator_generate_sequence(SequenceGenerator *self) {
    return self->data;
}

void PValueCalculator_init(PValueCalculator *self, double *sequence1, double *sequence2) {
    self->sequence1 = sequence1;
    self->sequence2 = sequence2;
}

double PValueCalculator_calculate_p_value(PValueCalculator *self) {
    double diff = 0.0;
    for (int i = 0; i < SIZE1; i++) {
        diff += self->sequence1[i];
    }
    diff /= SIZE1;
    for (int i = 0; i < SIZE2; i++) {
        diff -= self->sequence2[i];
    }
    diff /= SIZE2;

    double bootstrap_samples[BOOTSTRAP_SAMPLES];
    for (int i = 0; i < BOOTSTRAP_SAMPLES; i++) {
        double combined[SIZE1 + SIZE2];
        for (int j = 0; j < SIZE1; j++) {
            combined[j] = self->sequence1[j];
        }
        for (int j = 0; j < SIZE2; j++) {
            combined[j + SIZE1] = self->sequence2[j];
        }
        for (int j = 0; j < SIZE1 + SIZE2; j++) {
            int k = j + (rand() % (SIZE1 + SIZE2 - j));
            double temp = combined[j];
            combined[j] = combined[k];
            combined[k] = temp;
        }
        double new_mean_diff = 0.0;
        for (int j = 0; j < SIZE1; j++) {
            new_mean_diff += combined[j];
        }
        new_mean_diff /= SIZE1;
        for (int j = 0; j < SIZE2; j++) {
            new_mean_diff -= combined[j + SIZE1];
        }
        new_mean_diff /= SIZE2;
        bootstrap_samples[i] = new_mean_diff;
    }

    double p_value = 1.0;
    for (int i = 0; i < BOOTSTRAP_SAMPLES; i++) {
        if (fabs(bootstrap_samples[i]) >= fabs(diff)) {
            p_value++;
        }
    }
    p_value /= (BOOTSTRAP_SAMPLES + 1);

    return p_value;
}

void AnalysisRunner_init(AnalysisRunner *self, SequenceGenerator *sequence_generator1, SequenceGenerator *sequence_generator2) {
    self->sequence_generator1 = sequence_generator1;
    self->sequence_generator2 = sequence_generator2;
}

double AnalysisRunner_run_analysis(AnalysisRunner *self) {
    double *seq1 = SequenceGenerator_generate_sequence(self->sequence_generator1);
    double *seq2 = SequenceGenerator_generate_sequence(self->sequence_generator2);
    PValueCalculator p_value_calculator;
    PValueCalculator_init(&p_value_calculator, seq1, seq2);
    return PValueCalculator_calculate_p_value(&p_value_calculator);
}

int main() {
    srand(time(NULL));
    SequenceGenerator seq_gen1, seq_gen2;
    SequenceGenerator_init(&seq_gen1, SIZE1);
    SequenceGenerator_init(&seq_gen2, SIZE2);
    AnalysisRunner analysis_runner;
    AnalysisRunner_init(&analysis_runner, &seq_gen1, &seq_gen2);
    double result = AnalysisRunner_run_analysis(&analysis_runner);
    printf("%f\n", result);
    return 0;
}