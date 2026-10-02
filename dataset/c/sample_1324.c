c
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to generate random data
void generate_data(double *group1, double *group2, int size) {
    for (int i = 0; i < size; i++) {
        group1[i] = 5 + 2 * sqrt(-2 * log((double)rand() / RAND_MAX)) * cos(2 * M_PI * (double)rand() / RAND_MAX);
        group2[i] = 5.5 + 2.5 * sqrt(-2 * log((double)rand() / RAND_MAX)) * cos(2 * M_PI * (double)rand() / RAND_MAX);
    }
}

// Function to calculate the t-test p-value
double ttest(double *group1, double *group2, int size) {
    double mean1 = 0, mean2 = 0;
    for (int i = 0; i < size; i++) {
        mean1 += group1[i];
        mean2 += group2[i];
    }
    mean1 /= size;
    mean2 /= size;

    double var1 = 0, var2 = 0;
    for (int i = 0; i < size; i++) {
        var1 += pow(group1[i] - mean1, 2);
        var2 += pow(group2[i] - mean2, 2);
    }
    var1 /= size;
    var2 /= size;

    double se = sqrt(var1 / size + var2 / size);
    double t = (mean1 - mean2) / se;
    return 2 * (1 - tgamma(0.5 * (2 * size + 1)) * pow(t / sqrt(size * (size + 1)), 0.5 * (2 * size + 1)) / tgamma(0.5 * (2 * size)));
}

// Function to calculate p-values using permutations
void calculate_pvalue_permutations(double *group1, double *group2, double *pvalues, int size, int iterations) {
    double *combined = (double *)malloc(2 * size * sizeof(double));
    for (int i = 0; i < iterations; i++) {
        for (int j = 0; j < 2 * size; j++) {
            combined[j] = j < size ? group1[j] : group2[j - size];
        }
        for (int j = 0; j < 2 * size; j++) {
            int r = j + (rand() % (2 * size - j));
            double temp = combined[j];
            combined[j] = combined[r];
            combined[r] = temp;
        }
        for (int j = 0; j < size; j++) {
            group1[j] = combined[j];
            group2[j] = combined[j + size];
        }
        pvalues[i] = ttest(group1, group2, size);
    }
    free(combined);
}

int main() {
    int size = 30;
    int permutations = 1000;
    double *group1 = (double *)malloc(size * sizeof(double));
    double *group2 = (double *)malloc(size * sizeof(double));
    double *pvalues = (double *)malloc(permutations * sizeof(double));

    generate_data(group1, group2, size);
    calculate_pvalue_permutations(group1, group2, pvalues, size, permutations);

    double mean_pvalue = 0;
    for (int i = 0; i < permutations; i++) {
        mean_pvalue += pvalues[i];
    }
    mean_pvalue /= permutations;

    printf("%f\n", mean_pvalue);

    free(group1);
    free(group2);
    free(pvalues);

    return 0;
}