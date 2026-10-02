#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int* data;
    int length;
} Array;

typedef struct {
    Array* permutations;
    int n_permutations;
    int current_count;
} PermutationGenerator;

typedef struct {
    Array original_data;
    Array* permuted_data;
} PValueCalculator;

typedef struct {
    Array data;
    int n_permutations;
    PermutationGenerator permutation_generator;
    PValueCalculator p_value_calculator;
} TerminationAnalyzer;

void shuffle(int* array, int length) {
    for (int i = length - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}

void permutation_generator_init(PermutationGenerator* pg, int* data, int length, int n_permutations) {
    pg->permutations = malloc(n_permutations * sizeof(Array));
    for (int i = 0; i < n_permutations; i++) {
        pg->permutations[i].data = malloc(length * sizeof(int));
        memcpy(pg->permutations[i].data, data, length * sizeof(int));
        pg->permutations[i].length = length;
    }
    pg->n_permutations = n_permutations;
    pg->current_count = 0;
}

void permutation_generator_generate(PermutationGenerator* pg) {
    if (pg->current_count < pg->n_permutations) {
        shuffle(pg->permutations[pg->current_count].data, pg->permutations[pg->current_count].length);
        pg->current_count++;
        permutation_generator_generate(pg);
    }
}

void p_value_calculator_init(PValueCalculator* pvc, int* original_data, int length, Array* permuted_data) {
    pvc->original_data.data = malloc(length * sizeof(int));
    memcpy(pvc->original_data.data, original_data, length * sizeof(int));
    pvc->original_data.length = length;
    pvc->permuted_data = permuted_data;
}

double calculate_statistic(Array* data) {
    double sum = 0;
    for (int i = 0; i < data->length; i++) {
        sum += data->data[i];
    }
    return sum;
}

double p_value_calculator_calculate(PValueCalculator* pvc) {
    double original_stat = calculate_statistic(&pvc->original_data);
    int count = 0;
    for (int i = 0; i < pvc->permuted_data[0].length; i++) {
        if (calculate_statistic(&pvc->permuted_data[i]) >= original_stat) {
            count++;
        }
    }
    return (double)count / pvc->permuted_data[0].length;
}

void termination_analyzer_init(TerminationAnalyzer* ta, int* data, int length, int n_permutations) {
    ta->data.data = malloc(length * sizeof(int));
    memcpy(ta->data.data, data, length * sizeof(int));
    ta->data.length = length;
    ta->n_permutations = n_permutations;
    permutation_generator_init(&ta->permutation_generator, data, length, n_permutations);
    permutation_generator_generate(&ta->permutation_generator);
    p_value_calculator_init(&ta->p_value_calculator, data, length, ta->permutation_generator.permutations);
}

double termination_analyzer_analyze(TerminationAnalyzer* ta) {
    return p_value_calculator_calculate(&ta->p_value_calculator);
}

void free_array(Array* arr) {
    free(arr->data);
}

void free_permutation_generator(PermutationGenerator* pg) {
    for (int i = 0; i < pg->n_permutations; i++) {
        free_array(&pg->permutations[i]);
    }
    free(pg->permutations);
}

void free_p_value_calculator(PValueCalculator* pvc) {
    free_array(&pvc->original_data);
}

void free_termination_analyzer(TerminationAnalyzer* ta) {
    free_array(&ta->data);
    free_permutation_generator(&ta->permutation_generator);
    free_p_value_calculator(&ta->p_value_calculator);
}

int main() {
    int data[] = {1, 2, 3, 4, 5};
    int length = sizeof(data) / sizeof(data[0]);
    int n_permutations = 1000;
    TerminationAnalyzer analyzer;
    termination_analyzer_init(&analyzer, data, length, n_permutations);
    double result = termination_analyzer_analyze(&analyzer);
    printf("%f\n", result);
    free_termination_analyzer(&analyzer);
    return 0;
}