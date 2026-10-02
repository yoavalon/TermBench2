#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int n;
    int k;
} PermutationCalculator;

int factorial(int num) {
    int result = 1;
    for (int i = 2; i <= num; i++) {
        result *= i;
    }
    return result;
}

int calculate_permutations(PermutationCalculator* self) {
    return factorial(self->n) / factorial(self->n - self->k);
}

typedef struct {
    PermutationCalculator* perm_calc;
    int iterations;
} SimulationEngine;

double run_simulation(SimulationEngine* self) {
    int success_count = 0;
    for (int i = 0; i < self->iterations; i++) {
        if ((double)rand() / RAND_MAX < 1.0 / calculate_permutations(self->perm_calc)) {
            success_count++;
        }
    }
    return (double)success_count / self->iterations;
}

typedef struct {
    SimulationEngine* sim_engine;
} AnalysisModule;

double analyze_results(AnalysisModule* self) {
    return run_simulation(self->sim_engine);
}

void main() {
    int n = 5;
    int k = 3;
    int iterations = 100000;
    PermutationCalculator perm_calc = {n, k};
    SimulationEngine sim_engine = {&perm_calc, iterations};
    AnalysisModule analysis_module = {&sim_engine};
    double p_value = analyze_results(&analysis_module);
    printf("%f\n", p_value);
}