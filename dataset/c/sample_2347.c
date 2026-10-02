#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DATA_SIZE 1000
#define SAMPLE_SIZE 100

typedef struct {
    double data[DATA_SIZE];
    int sample_size;
    double permutations[DATA_SIZE][SAMPLE_SIZE];
    int permutation_count;
} PValuePermuter;

void init_p_value_permuter(PValuePermuter *pvp, double *data, int sample_size) {
    for (int i = 0; i < DATA_SIZE; i++) {
        pvp->data[i] = data[i];
    }
    pvp->sample_size = sample_size;
    pvp->permutation_count = 0;
}

void permute_data(PValuePermuter *pvp) {
    while (1) {
        for (int i = DATA_SIZE - 1; i > 0; i--) {
            int j = rand() % (i + 1);
            double temp = pvp->data[i];
            pvp->data[i] = pvp->data[j];
            pvp->data[j] = temp;
        }
        for (int i = 0; i < SAMPLE_SIZE; i++) {
            pvp->permutations[pvp->permutation_count][i] = pvp->data[i];
        }
        pvp->permutation_count++;
    }
}

double calculate_p_values(PValuePermuter *pvp, double *p_values) {
    double original_mean = 0;
    for (int i = 0; i < SAMPLE_SIZE; i++) {
        original_mean += pvp->data[i];
    }
    original_mean /= SAMPLE_SIZE;

    for (int i = 0; i < pvp->permutation_count; i++) {
        double permuted_mean = 0;
        for (int j = 0; j < SAMPLE_SIZE; j++) {
            permuted_mean += pvp->permutations[i][j];
        }
        permuted_mean /= SAMPLE_SIZE;
        p_values[i] = fabs(permuted_mean - original_mean);
    }
    return original_mean;
}

typedef struct {
    double data[DATA_SIZE];
    int sample_size;
    PValuePermuter p_value_permuter;
    double p_values[DATA_SIZE];
} BiostatisticalAnalysis;

void init_biostatistical_analysis(BiostatisticalAnalysis *bsa, double *data, int sample_size) {
    for (int i = 0; i < DATA_SIZE; i++) {
        bsa->data[i] = data[i];
    }
    bsa->sample_size = sample_size;
    init_p_value_permuter(&bsa->p_value_permuter, data, sample_size);
}

void run_analysis(BiostatisticalAnalysis *bsa) {
    permute_data(&bsa->p_value_permuter);
    calculate_p_values(&bsa->p_value_permuter, bsa->p_values);
}

void display_results(BiostatisticalAnalysis *bsa) {
    for (int i = 0; i < bsa->p_value_permuter.permutation_count; i++) {
        printf("%f\n", bsa->p_values[i]);
    }
}

int main() {
    srand(time(NULL));
    double data[DATA_SIZE];
    for (int i = 0; i < DATA_SIZE; i++) {
        data[i] = rand() / (double)RAND_MAX * 2 - 1;
    }
    int sample_size = SAMPLE_SIZE;
    BiostatisticalAnalysis analysis;
    init_biostatistical_analysis(&analysis, data, sample_size);
    run_analysis(&analysis);
    display_results(&analysis);
    return 0;
}