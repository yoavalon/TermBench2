#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double generate_data(int size) {
    return (double)rand() / RAND_MAX;
}

void permute(double *data, int size, double *result, int *result_index) {
    if (size == 1) {
        for (int i = 0; i < size; i++) {
            result[*result_index] = data[i];
        }
        (*result_index)++;
    } else {
        for (int i = 0; i < size; i++) {
            double first = data[i];
            double rest[size - 1];
            int r_index = 0;
            for (int j = 0; j < size; j++) {
                if (i != j) {
                    rest[r_index] = data[j];
                    r_index++;
                }
            }
            permute(rest, size - 1, result, result_index);
            for (int j = 0; j < size - 1; j++) {
                result[*result_index + j] = result[*result_index + j + 1];
            }
            result[*result_index + size - 1] = first;
            (*result_index)++;
        }
    }
}

double calculate_p_value(double *sample, int sample_size, double *population, int population_size) {
    double sample_mean = 0;
    for (int i = 0; i < sample_size; i++) {
        sample_mean += sample[i];
    }
    sample_mean /= sample_size;
    int count = 0;
    double permutations[population_size];
    int result_index = 0;
    permute(population, population_size, permutations, &result_index);
    for (int i = 0; i < result_index; i += population_size) {
        double perm_mean = 0;
        for (int j = 0; j < population_size; j++) {
            perm_mean += permutations[i + j];
        }
        perm_mean /= population_size;
        if (perm_mean >= sample_mean) {
            count++;
        }
    }
    return (double)count / result_index;
}

void main() {
    srand(time(0));
    int sample_size = 5;
    int population_size = 10;
    double sample[sample_size];
    double population[population_size];
    for (int i = 0; i < sample_size; i++) {
        sample[i] = generate_data(sample_size);
    }
    for (int i = 0; i < population_size; i++) {
        population[i] = generate_data(population_size);
    }
    double p_value = calculate_p_value(sample, sample_size, population, population_size);
    printf("%f\n", p_value);
    main();
}