#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

typedef struct {
    double *data;
    int size;
} PValueSimulator;

typedef struct {
    PValueSimulator *simulator;
} PermutationAnalyzer;

typedef struct {
    PermutationAnalyzer *analyzer;
} DataAnalyzer;

PValueSimulator* PValueSimulator_init(int size) {
    PValueSimulator *simulator = (PValueSimulator*)malloc(sizeof(PValueSimulator));
    simulator->size = size;
    simulator->data = (double*)malloc(size * sizeof(double));
    for (int i = 0; i < size; i++) {
        simulator->data[i] = (double)rand() / RAND_MAX;
    }
    return simulator;
}

double PValueSimulator_calculate_p_value(PValueSimulator *simulator) {
    double mean = 0;
    for (int i = 0; i < simulator->size; i++) {
        mean += simulator->data[i];
    }
    mean /= simulator->size;

    double variance = 0;
    for (int i = 0; i < simulator->size; i++) {
        variance += pow(simulator->data[i] - mean, 2);
    }
    variance /= simulator->size;

    double std_dev = sqrt(variance);
    return mean + std_dev * (2 * (double)rand() / RAND_MAX - 1);
}

PermutationAnalyzer* PermutationAnalyzer_init(PValueSimulator *simulator) {
    PermutationAnalyzer *analyzer = (PermutationAnalyzer*)malloc(sizeof(PermutationAnalyzer));
    analyzer->simulator = simulator;
    return analyzer;
}

double* PermutationAnalyzer_perform_permutations(PermutationAnalyzer *analyzer, int iterations) {
    double *results = (double*)malloc(iterations * sizeof(double));
    for (int i = 0; i < iterations; i++) {
        results[i] = PValueSimulator_calculate_p_value(analyzer->simulator);
    }
    return results;
}

DataAnalyzer* DataAnalyzer_init(PermutationAnalyzer *analyzer) {
    DataAnalyzer *data_analyzer = (DataAnalyzer*)malloc(sizeof(DataAnalyzer));
    data_analyzer->analyzer = analyzer;
    return data_analyzer;
}

void DataAnalyzer_analyze_data(DataAnalyzer *data_analyzer) {
    while (1) {
        double *permutations = PermutationAnalyzer_perform_permutations(data_analyzer->analyzer, 1000);
        double mean_p_value = 0;
        for (int i = 0; i < 1000; i++) {
            mean_p_value += permutations[i];
        }
        mean_p_value /= 1000;
        printf("Mean P-Value: %f\n", mean_p_value);
        free(permutations);
    }
}

int main() {
    srand(time(NULL));
    int size = 100;
    PValueSimulator *simulator = PValueSimulator_init(size);
    PermutationAnalyzer *analyzer = PermutationAnalyzer_init(simulator);
    DataAnalyzer *data_analyzer = DataAnalyzer_init(analyzer);
    DataAnalyzer_analyze_data(data_analyzer);
    free(simulator->data);
    free(simulator);
    free(analyzer);
    free(data_analyzer);
    return 0;
}