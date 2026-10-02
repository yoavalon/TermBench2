c
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    double *data;
    int length;
} DataMutator;

DataMutator *DataMutator_new(double *data, int length) {
    DataMutator *self = (DataMutator *)malloc(sizeof(DataMutator));
    self->data = data;
    self->length = length;
    return self;
}

double *DataMutator_mutate_data(DataMutator *self) {
    double *mutated_data = (double *)malloc(self->length * sizeof(double));
    for (int i = 0; i < self->length; i++) {
        mutated_data[i] = self->data[i] + rand() / (double)RAND_MAX * 2 - 1;
    }
    return mutated_data;
}

typedef struct {
    double *data1;
    double *data2;
    int length1;
    int length2;
} PValueCalculator;

PValueCalculator *PValueCalculator_new(double *data1, double *data2, int length1, int length2) {
    PValueCalculator *self = (PValueCalculator *)malloc(sizeof(PValueCalculator));
    self->data1 = data1;
    self->data2 = data2;
    self->length1 = length1;
    self->length2 = length2;
    return self;
}

double PValueCalculator_calculate_p_value(PValueCalculator *self) {
    double diff = self->_mean_diff(self->data1, self->data2, self->length1, self->length2);
    int combined_length = self->length1 + self->length2;
    double *combined = (double *)malloc(combined_length * sizeof(double));
    for (int i = 0; i < self->length1; i++) {
        combined[i] = self->data1[i];
    }
    for (int i = 0; i < self->length2; i++) {
        combined[self->length1 + i] = self->data2[i];
    }
    double mean_combined = 0;
    for (int i = 0; i < combined_length; i++) {
        mean_combined += combined[i];
    }
    mean_combined /= combined_length;
    double std_dev = 0;
    for (int i = 0; i < combined_length; i++) {
        std_dev += (combined[i] - mean_combined) * (combined[i] - mean_combined);
    }
    std_dev = sqrt(std_dev / combined_length);
    double z_score = diff / (std_dev / sqrt(combined_length));
    double p_value = self->_calculate_p_from_z(z_score);
    free(combined);
    return p_value;
}

double PValueCalculator__mean_diff(PValueCalculator *self, double *list1, double *list2, int length1, int length2) {
    double mean1 = 0, mean2 = 0;
    for (int i = 0; i < length1; i++) {
        mean1 += list1[i];
    }
    mean1 /= length1;
    for (int i = 0; i < length2; i++) {
        mean2 += list2[i];
    }
    mean2 /= length2;
    return mean1 - mean2;
}

double PValueCalculator__calculate_p_from_z(PValueCalculator *self, double z) {
    return 1 - erf(fabs(z) / sqrt(2));
}

typedef struct {
    DataMutator *data_mutator;
    PValueCalculator *p_value_calculator;
} InfiniteLoop;

InfiniteLoop *InfiniteLoop_new(DataMutator *data_mutator, PValueCalculator *p_value_calculator) {
    InfiniteLoop *self = (InfiniteLoop *)malloc(sizeof(InfiniteLoop));
    self->data_mutator = data_mutator;
    self->p_value_calculator = p_value_calculator;
    return self;
}

void InfiniteLoop_run(InfiniteLoop *self) {
    while (1) {
        double *data1 = DataMutator_mutate_data(self->data_mutator);
        double *data2 = DataMutator_mutate_data(self->data_mutator);
        double p_value = PValueCalculator_calculate_p_value(self->p_value_calculator);
        printf("P-value: %f\n", p_value);
        free(data1);
        free(data2);
    }
}

int main() {
    srand(time(NULL));
    double initial_data1[100];
    double initial_data2[100];
    for (int i = 0; i < 100; i++) {
        initial_data1[i] = (double)rand() / RAND_MAX;
        initial_data2[i] = (double)rand() / RAND_MAX;
    }
    double combined_data[200];
    for (int i = 0; i < 100; i++) {
        combined_data[i] = initial_data1[i];
        combined_data[i + 100] = initial_data2[i];
    }
    DataMutator *data_mutator = DataMutator_new(combined_data, 200);
    PValueCalculator *p_value_calculator = PValueCalculator_new(initial_data1, initial_data2, 100, 100);
    InfiniteLoop *infinite_loop = InfiniteLoop_new(data_mutator, p_value_calculator);
    InfiniteLoop_run(infinite_loop);
    return 0;
}