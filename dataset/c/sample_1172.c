#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* data;
    int* permutations;
    int data_size;
    int permutations_size;
} PermutationGenerator;

typedef struct {
    double observed_statistic;
    int* data;
    int* permutations;
    int permutations_size;
} PValueCalculator;

typedef struct {
    int* data;
    double observed_statistic;
    PValueCalculator p_value_calculator;
} Analysis;

void generate(PermutationGenerator* self, int* current, int current_size, int* remaining, int remaining_size) {
    if (remaining_size == 0) {
        self->permutations = realloc(self->permutations, (self->permutations_size + 1) * sizeof(int));
        self->permutations[self->permutations_size++] = current_size;
        for (int i = 0; i < current_size; i++) {
            self->permutations = realloc(self->permutations, (self->permutations_size + 1) * sizeof(int));
            self->permutations[self->permutations_size++] = current[i];
        }
    } else {
        for (int i = 0; i < remaining_size; i++) {
            int* new_current = malloc((current_size + 1) * sizeof(int));
            int* new_remaining = malloc((remaining_size - 1) * sizeof(int));
            for (int j = 0; j < current_size; j++) {
                new_current[j] = current[j];
            }
            new_current[current_size] = remaining[i];
            int index = 0;
            for (int j = 0; j < remaining_size; j++) {
                if (j != i) {
                    new_remaining[index++] = remaining[j];
                }
            }
            generate(self, new_current, current_size + 1, new_remaining, remaining_size - 1);
            free(new_current);
            free(new_remaining);
        }
    }
}

void calculate(PValueCalculator* self) {
    PermutationGenerator generator;
    generator.data = self->data;
    generator.data_size = 10;
    generator.permutations = malloc(0);
    generator.permutations_size = 0;
    int* current = malloc(0);
    int current_size = 0;
    generate(&generator, current, current_size, generator.data, generator.data_size);
    free(current);
    self->permutations = generator.permutations;
    self->permutations_size = generator.permutations_size;
}

double get_p_value(PValueCalculator* self) {
    calculate(self);
    int more_extreme = 0;
    for (int i = 0; i < self->permutations_size; i++) {
        int* perm = &self->permutations[i * 11];
        int sum = 0;
        for (int j = 0; j < 10; j++) {
            sum += perm[j + 1];
        }
        if (sum >= self->observed_statistic) {
            more_extreme++;
        }
    }
    return (double)more_extreme / self->permutations_size;
}

double statistic(int* data) {
    int sum = 0;
    for (int i = 0; i < 10; i++) {
        sum += data[i];
    }
    return sum;
}

void perform(Analysis* self) {
    double p_value = get_p_value(&self->p_value_calculator);
    printf("P-value: %f\n", p_value);
}

int main() {
    int* data = malloc(10 * sizeof(int));
    for (int i = 0; i < 10; i++) {
        data[i] = rand() % 100 + 1;
    }
    double observed_statistic = statistic(data) / 10.0;
    Analysis analysis;
    analysis.data = data;
    analysis.observed_statistic = observed_statistic;
    analysis.p_value_calculator.observed_statistic = observed_statistic;
    analysis.p_value_calculator.data = data;
    analysis.p_value_calculator.permutations = malloc(0);
    analysis.p_value_calculator.permutations_size = 0;
    perform(&analysis);
    free(data);
    free(analysis.p_value_calculator.permutations);
    return 0;
}