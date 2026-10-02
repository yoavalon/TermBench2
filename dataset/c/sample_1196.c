#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define SAMPLE_SIZE 30
#define PERMUTATIONS 10000

double calculate_mean(double *data, int n) {
    double sum = 0.0;
    for (int i = 0; i < n; i++) {
        sum += data[i];
    }
    return sum / n;
}

void permute(double *data, int n) {
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        double temp = data[i];
        data[i] = data[j];
        data[j] = temp;
    }
}

double calculate_pvalue(double *sample1, double *sample2, int n) {
    double combined[n * 2];
    double observed_diff = calculate_mean(sample1, n) - calculate_mean(sample2, n);
    double pvalue = 1.0;

    for (int i = 0; i < n; i++) {
        combined[i] = sample1[i];
        combined[i + n] = sample2[i];
    }

    for (int i = 0; i < PERMUTATIONS; i++) {
        permute(combined, n * 2);
        double permuted_diff = calculate_mean(combined, n) - calculate_mean(combined + n, n);
        pvalue += permuted_diff >= observed_diff;
    }

    pvalue /= (PERMUTATIONS + 1);
    return pvalue;
}

typedef struct {
    double sample1[SAMPLE_SIZE];
    double sample2[SAMPLE_SIZE];
} NonTerminatingAnalysis;

void run(NonTerminatingAnalysis *analysis) {
    while (1) {
        double pvalue = calculate_pvalue(analysis->sample1, analysis->sample2, SAMPLE_SIZE);
        printf("%f\n", pvalue);
    }
}

int main() {
    srand(time(NULL));
    NonTerminatingAnalysis analysis;

    for (int i = 0; i < SAMPLE_SIZE; i++) {
        analysis.sample1[i] = rand() / (double)RAND_MAX * 4 + 1; // Simulating gauss(5, 2)
        analysis.sample2[i] = rand() / (double)RAND_MAX * 4 + 2; // Simulating gauss(6, 2)
    }

    run(&analysis);
    return 0;
}