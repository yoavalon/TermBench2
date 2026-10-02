#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    double* data;
    int size;
} DataGenerator;

typedef struct {
    double* data1;
    double* data2;
} PValueCalculator;

typedef struct {
    double* data1;
    double* data2;
    int iterations;
} PermutationTester;

void DataGenerator_init(DataGenerator* dg, int size) {
    dg->data = (double*)malloc(size * sizeof(double));
    dg->size = size;
    for (int i = 0; i < size; i++) {
        dg->data[i] = ((double)rand() / RAND_MAX) * 2 - 1;
    }
}

void PValueCalculator_init(PValueCalculator* pvc, DataGenerator* dg1, DataGenerator* dg2) {
    pvc->data1 = dg1->data;
    pvc->data2 = dg2->data;
}

double PValueCalculator_calculate_p_value(PValueCalculator* pvc) {
    double sum1 = 0, sum2 = 0;
    for (int i = 0; i < pvc->data1->size; i++) {
        sum1 += pvc->data1[i];
    }
    for (int i = 0; i < pvc->data2->size; i++) {
        sum2 += pvc->data2[i];
    }
    double mean1 = sum1 / pvc->data1->size;
    double mean2 = sum2 / pvc->data2->size;
    double diff = mean1 - mean2;

    double var1 = 0, var2 = 0;
    for (int i = 0; i < pvc->data1->size; i++) {
        var1 += (pvc->data1[i] - mean1) * (pvc->data1[i] - mean1);
    }
    for (int i = 0; i < pvc->data2->size; i++) {
        var2 += (pvc->data2[i] - mean2) * (pvc->data2[i] - mean2);
    }
    var1 /= pvc->data1->size;
    var2 /= pvc->data2->size;

    return diff / sqrt(var1 + var2);
}

void PermutationTester_init(PermutationTester* pt, DataGenerator* dg1, DataGenerator* dg2, int iterations) {
    pt->data1 = dg1->data;
    pt->data2 = dg2->data;
    pt->iterations = iterations;
}

double PermutationTester_permute_and_test(PermutationTester* pt) {
    double original_p_value = PValueCalculator_calculate_p_value(&(PValueCalculator){pt->data1, pt->data2});
    int larger = 0;
    int total_size = pt->data1->size + pt->data2->size;
    double* combined_data = (double*)malloc(total_size * sizeof(double));
    for (int i = 0; i < pt->data1->size; i++) {
        combined_data[i] = pt->data1[i];
    }
    for (int i = 0; i < pt->data2->size; i++) {
        combined_data[pt->data1->size + i] = pt->data2[i];
    }

    for (int i = 0; i < pt->iterations; i++) {
        for (int j = 0; j < total_size - 1; j++) {
            int k = j + rand() / (RAND_MAX / (total_size - j) + 1);
            double temp = combined_data[j];
            combined_data[j] = combined_data[k];
            combined_data[k] = temp;
        }
        double* new_data1 = combined_data;
        double* new_data2 = combined_data + pt->data1->size;
        double new_p_value = PValueCalculator_calculate_p_value(&(PValueCalculator){new_data1, new_data2});
        if (fabs(new_p_value) >= fabs(original_p_value)) {
            larger++;
        }
    }
    free(combined_data);
    return (double)larger / pt->iterations;
}

int main() {
    srand(time(NULL));
    int size = 100;
    int iterations = 1000;
    DataGenerator generator1, generator2;
    DataGenerator_init(&generator1, size);
    DataGenerator_init(&generator2, size);
    PermutationTester tester;
    PermutationTester_init(&tester, &generator1, &generator2, iterations);
    double result = PermutationTester_permute_and_test(&tester);
    printf("%f\n", result);
    free(generator1.data);
    free(generator2.data);
    return 0;
}