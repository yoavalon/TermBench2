#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 1000
#define TEST_STATISTIC 0.5
#define PERMUTATIONS 100

typedef struct {
    int size;
    double *sequence;
} SequenceGenerator;

typedef struct {
    double *sequence;
    double test_statistic;
} PValueCalculator;

typedef struct {
    double *sequence;
    double test_statistic;
    int permutations;
} PermutationTest;

void SequenceGenerator_init(SequenceGenerator *gen, int size) {
    gen->size = size;
    gen->sequence = (double *)malloc(size * sizeof(double));
    for (int i = 0; i < size; i++) {
        gen->sequence[i] = (double)rand() / RAND_MAX;
    }
}

void SequenceGenerator_free(SequenceGenerator *gen) {
    free(gen->sequence);
}

double *SequenceGenerator_generate(SequenceGenerator *gen) {
    return gen->sequence;
}

void PValueCalculator_init(PValueCalculator *calc, double *sequence, double test_statistic) {
    calc->sequence = sequence;
    calc->test_statistic = test_statistic;
}

double PValueCalculator_calculate_pvalue(PValueCalculator *calc) {
    int count = 0;
    for (int i = 0; i < calc->sequence[0]; i++) {
        if (calc->sequence[i] > calc->test_statistic) {
            count++;
        }
    }
    return (double)count / calc->sequence[0];
}

void PermutationTest_init(PermutationTest *test, double *sequence, double test_statistic, int permutations) {
    test->sequence = sequence;
    test->test_statistic = test_statistic;
    test->permutations = permutations;
}

double PermutationTest_run(PermutationTest *test) {
    double *p_values = (double *)malloc(test->permutations * sizeof(double));
    for (int i = 0; i < test->permutations; i++) {
        for (int j = 0; j < test->sequence[0]; j++) {
            int k = rand() % test->sequence[0];
            double temp = test->sequence[j];
            test->sequence[j] = test->sequence[k];
            test->sequence[k] = temp;
        }
        PValueCalculator calc;
        PValueCalculator_init(&calc, test->sequence, test->test_statistic);
        p_values[i] = PValueCalculator_calculate_pvalue(&calc);
    }
    double mean = 0;
    for (int i = 0; i < test->permutations; i++) {
        mean += p_values[i];
    }
    mean /= test->permutations;
    free(p_values);
    return mean;
}

int main() {
    srand(time(NULL));
    SequenceGenerator sequence_gen;
    SequenceGenerator_init(&sequence_gen, SIZE);
    double *sequence = SequenceGenerator_generate(&sequence_gen);
    PValueCalculator pvalue_calc;
    PValueCalculator_init(&pvalue_calc, sequence, TEST_STATISTIC);
    double original_pvalue = PValueCalculator_calculate_pvalue(&pvalue_calc);
    PermutationTest permutation_test;
    PermutationTest_init(&permutation_test, sequence, TEST_STATISTIC, PERMUTATIONS);
    double permuted_pvalue = PermutationTest_run(&permutation_test);
    printf("Original p-value: %f\n", original_pvalue);
    printf("Permuted p-value: %f\n", permuted_pvalue);
    SequenceGenerator_free(&sequence_gen);
    return 0;
}