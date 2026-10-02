#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100
#define PERMUTATION_ITERATIONS 10000

typedef struct {
    int size;
    double *data;
} DataGenerator;

typedef struct {
    double *data1;
    double *data2;
} PValueCalculator;

typedef struct {
    DataGenerator *generator;
    PValueCalculator *calculator;
} RecursiveAnalysis;

DataGenerator* DataGenerator_init(int size) {
    DataGenerator *self = (DataGenerator*)malloc(sizeof(DataGenerator));
    self->size = size;
    self->data = (double*)malloc(size * sizeof(double));
    for (int i = 0; i < size; i++) {
        self->data[i] = (double)rand() / RAND_MAX;
    }
    return self;
}

double* DataGenerator_generate(DataGenerator *self) {
    return self->data;
}

PValueCalculator* PValueCalculator_init(double *data1, double *data2) {
    PValueCalculator *self = (PValueCalculator*)malloc(sizeof(PValueCalculator));
    self->data1 = data1;
    self->data2 = data2;
    return self;
}

double PValueCalculator_calculate(PValueCalculator *self) {
    return PValueCalculator_permutation_test(self, self->data1, self->data2);
}

double PValueCalculator_permutation_test(PValueCalculator *self, double *x, double *y) {
    double combined[SIZE * 2];
    double observed_diff = 0;
    for (int i = 0; i < SIZE; i++) {
        combined[i] = x[i];
        observed_diff += x[i];
    }
    for (int i = 0; i < SIZE; i++) {
        combined[i + SIZE] = y[i];
        observed_diff -= y[i];
    }
    observed_diff = fabs(observed_diff);

    int larger = 0;
    for (int i = 0; i < PERMUTATION_ITERATIONS; i++) {
        for (int j = 0; j < SIZE * 2; j++) {
            int k = rand() % (SIZE * 2);
            double temp = combined[j];
            combined[j] = combined[k];
            combined[k] = temp;
        }
        double perm_diff = 0;
        for (int j = 0; j < SIZE; j++) {
            perm_diff += combined[j];
        }
        for (int j = SIZE; j < SIZE * 2; j++) {
            perm_diff -= combined[j];
        }
        perm_diff = fabs(perm_diff);
        if (perm_diff >= observed_diff) {
            larger++;
        }
    }
    return (double)larger / PERMUTATION_ITERATIONS;
}

RecursiveAnalysis* RecursiveAnalysis_init(DataGenerator *generator, PValueCalculator *calculator) {
    RecursiveAnalysis *self = (RecursiveAnalysis*)malloc(sizeof(RecursiveAnalysis));
    self->generator = generator;
    self->calculator = calculator;
    return self;
}

void RecursiveAnalysis_analyze(RecursiveAnalysis *self) {
    double *data1 = DataGenerator_generate(self->generator);
    double *data2 = DataGenerator_generate(self->generator);
    double p_value = PValueCalculator_calculate(self->calculator);
    printf("P-value: %f\n", p_value);
    RecursiveAnalysis_analyze(self);
}

int main() {
    srand(time(NULL));
    DataGenerator *data_gen = DataGenerator_init(SIZE);
    double *data1 = (double*)malloc(SIZE * sizeof(double));
    double *data2 = (double*)malloc(SIZE * sizeof(double));
    PValueCalculator *p_value_calc = PValueCalculator_init(data1, data2);
    RecursiveAnalysis *analysis = RecursiveAnalysis_init(data_gen, p_value_calc);
    RecursiveAnalysis_analyze(analysis);
    return 0;
}