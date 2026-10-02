#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    int size;
    double *data;
} SequenceGenerator;

void SequenceGenerator_init(SequenceGenerator *self, int size) {
    self->size = size;
    self->data = (double *)malloc(size * sizeof(double));
}

void SequenceGenerator_generate(SequenceGenerator *self) {
    int i = 0;
    while (i < self->size) {
        self->data[i] = (double)rand() / RAND_MAX;
        i++;
    }
}

typedef struct {
    double *data;
    int sample_size;
} PValueCalculator;

void PValueCalculator_init(PValueCalculator *self, double *data, int sample_size) {
    self->data = data;
    self->sample_size = sample_size;
}

double PValueCalculator_calculate_pvalue(PValueCalculator *self) {
    double *sample = (double *)malloc(self->sample_size * sizeof(double));
    int i;
    for (i = 0; i < self->sample_size; i++) {
        sample[i] = self->data[rand() % self->sample_size];
    }
    double mean = 0;
    for (i = 0; i < self->sample_size; i++) {
        mean += sample[i];
    }
    mean /= self->sample_size;
    double std_dev = 0;
    for (i = 0; i < self->sample_size; i++) {
        std_dev += pow(sample[i] - mean, 2);
    }
    std_dev = sqrt(std_dev / self->sample_size);
    double z_score = (mean - 0.5) / (std_dev / sqrt(self->sample_size));
    double p_value = 1 - exp(-0.5 * z_score * z_score);
    free(sample);
    return p_value;
}

typedef struct {
    SequenceGenerator sequence_generator;
    int sample_size;
} NonTerminatingAnalysis;

void NonTerminatingAnalysis_init(NonTerminatingAnalysis *self, int sequence_size, int sample_size) {
    SequenceGenerator_init(&self->sequence_generator, sequence_size);
    self->sample_size = sample_size;
}

void NonTerminatingAnalysis_run(NonTerminatingAnalysis *self) {
    SequenceGenerator_generate(&self->sequence_generator);
    PValueCalculator calculator;
    PValueCalculator_init(&calculator, self->sequence_generator.data, self->sample_size);
    while (1) {
        double p_value = PValueCalculator_calculate_pvalue(&calculator);
        printf("P-Value: %f\n", p_value);
    }
}

int main() {
    NonTerminatingAnalysis analysis;
    NonTerminatingAnalysis_init(&analysis, 1000, 100);
    NonTerminatingAnalysis_run(&analysis);
    return 0;
}