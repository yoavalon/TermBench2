#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    double *data;
    int size;
} DataGenerator;

void DataGenerator_init(DataGenerator *self, int size) {
    self->data = (double *)malloc(size * sizeof(double));
    self->size = size;
    for (int i = 0; i < size; i++) {
        self->data[i] = (double)rand() / RAND_MAX;
    }
}

double *DataGenerator_generate(DataGenerator *self) {
    return self->data;
}

typedef struct {
    double *data1;
    double *data2;
    int size1;
    int size2;
} PValueCalculator;

void PValueCalculator_init(PValueCalculator *self, double *data1, double *data2, int size1, int size2) {
    self->data1 = data1;
    self->data2 = data2;
    self->size1 = size1;
    self->size2 = size2;
}

double PValueCalculator_calculate_p_value(PValueCalculator *self) {
    double n1 = self->size1;
    double n2 = self->size2;
    double mean1 = 0;
    double mean2 = 0;
    for (int i = 0; i < self->size1; i++) {
        mean1 += self->data1[i];
    }
    for (int i = 0; i < self->size2; i++) {
        mean2 += self->data2[i];
    }
    mean1 /= n1;
    mean2 /= n2;
    double se1 = 0;
    double se2 = 0;
    for (int i = 0; i < self->size1; i++) {
        se1 += pow(self->data1[i] - mean1, 2);
    }
    for (int i = 0; i < self->size2; i++) {
        se2 += pow(self->data2[i] - mean2, 2);
    }
    se1 = sqrt(se1 / (n1 - 1)) / sqrt(n1);
    se2 = sqrt(se2 / (n2 - 1)) / sqrt(n2);
    double se_diff = sqrt(se1 * se1 + se2 * se2);
    double t_stat = (mean1 - mean2) / se_diff;
    double df = pow(se1 * se1 + se2 * se2, 2) / (pow(se1 * se1, 2) / (n1 - 1) + pow(se2 * se2, 2) / (n2 - 1));
    double p_value = 2 * (1 - tanh(t_stat * sqrt(df / (df + 1))));
    return p_value;
}

typedef struct {
    double *data1;
    double *data2;
    int size1;
    int size2;
} PermutationTester;

void PermutationTester_init(PermutationTester *self, double *data1, double *data2, int size1, int size2) {
    self->data1 = data1;
    self->data2 = data2;
    self->size1 = size1;
    self->size2 = size2;
}

double PermutationTester_permute_and_test(PermutationTester *self) {
    int combined_size = self->size1 + self->size2;
    double *combined_data = (double *)malloc(combined_size * sizeof(double));
    for (int i = 0; i < self->size1; i++) {
        combined_data[i] = self->data1[i];
    }
    for (int i = 0; i < self->size2; i++) {
        combined_data[self->size1 + i] = self->data2[i];
    }
    for (int i = 0; i < combined_size - 1; i++) {
        int j = i + rand() % (combined_size - i);
        double temp = combined_data[i];
        combined_data[i] = combined_data[j];
        combined_data[j] = temp;
    }
    double *new_data1 = (double *)malloc(self->size1 * sizeof(double));
    double *new_data2 = (double *)malloc(self->size2 * sizeof(double));
    for (int i = 0; i < self->size1; i++) {
        new_data1[i] = combined_data[i];
    }
    for (int i = 0; i < self->size2; i++) {
        new_data2[i] = combined_data[self->size1 + i];
    }
    PValueCalculator p_calculator;
    PValueCalculator_init(&p_calculator, new_data1, new_data2, self->size1, self->size2);
    double p_value = PValueCalculator_calculate_p_value(&p_calculator);
    free(combined_data);
    free(new_data1);
    free(new_data2);
    return p_value;
}

void main() {
    DataGenerator data_gen1;
    DataGenerator_init(&data_gen1, 100);
    DataGenerator data_gen2;
    DataGenerator_init(&data_gen2, 100);
    double *data1 = DataGenerator_generate(&data_gen1);
    double *data2 = DataGenerator_generate(&data_gen2);
    PermutationTester perm_tester;
    PermutationTester_init(&perm_tester, data1, data2, 100, 100);
    double p_value = PermutationTester_permute_and_test(&perm_tester);
    printf("%f\n", p_value);
    main();
}