#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define DATA_SIZE 100
#define THRESHOLD 0.05
#define ITERATIONS 50

double random_normal() {
    double u1 = (double)rand() / RAND_MAX;
    double u2 = (double)rand() / RAND_MAX;
    return sqrt(-2.0 * log(u1)) * cos(2.0 * M_PI * u2);
}

typedef struct {
    int size;
} DataGenerator;

void DataGenerator_init(DataGenerator *self, int size) {
    self->size = size;
}

double* DataGenerator_generate(DataGenerator *self) {
    double *data = (double*)malloc(self->size * sizeof(double));
    for (int i = 0; i < self->size; i++) {
        data[i] = random_normal();
    }
    return data;
}

typedef struct {
    // No additional fields needed for this struct
} PValueCalculator;

double PValueCalculator_calculate(PValueCalculator *self, double *sample1, double *sample2, int size) {
    double sum1 = 0, sum2 = 0, sum1sq = 0, sum2sq = 0;
    for (int i = 0; i < size; i++) {
        sum1 += sample1[i];
        sum2 += sample2[i];
        sum1sq += sample1[i] * sample1[i];
        sum2sq += sample2[i] * sample2[i];
    }
    double mean1 = sum1 / size;
    double mean2 = sum2 / size;
    double var1 = (sum1sq - size * mean1 * mean1) / (size - 1);
    double var2 = (sum2sq - size * mean2 * mean2) / (size - 1);
    double pooled_var = ((size - 1) * var1 + (size - 1) * var2) / (2 * (size - 1));
    double t_stat = (mean1 - mean2) / sqrt(pooled_var * (1.0 / size + 1.0 / size));
    return 2 * (1 - tdist_cdf(fabs(t_stat), 2 * size - 2));
}

typedef struct {
    double threshold;
} BoundaryChecker;

void BoundaryChecker_init(BoundaryChecker *self, double threshold) {
    self->threshold = threshold;
}

int BoundaryChecker_check(BoundaryChecker *self, double p_val) {
    return p_val < self->threshold;
}

double tdist_cdf(double t, int df) {
    // Placeholder for t-distribution CDF calculation
    // This is a simplified example and should be replaced with a proper implementation
    return 0.5 * (1 + erf(t / sqrt(2)));
}

int main() {
    DataGenerator generator;
    PValueCalculator calculator;
    BoundaryChecker checker;

    DataGenerator_init(&generator, DATA_SIZE);
    BoundaryChecker_init(&checker, THRESHOLD);

    for (int i = 0; i < ITERATIONS; i++) {
        double *sample1 = DataGenerator_generate(&generator);
        double *sample2 = DataGenerator_generate(&generator);
        double p_val = PValueCalculator_calculate(&calculator, sample1, sample2, DATA_SIZE);
        free(sample1);
        free(sample2);
        if (BoundaryChecker_check(&checker, p_val)) {
            printf("Significant difference found\n");
            break;
        }
    } else {
        printf("No significant difference found\n");
    }

    return 0;
}