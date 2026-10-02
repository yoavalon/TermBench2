#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define ITERATIONS 10000

double permute_pvalue(double *data1, double *data2, int n1, int n2, int iterations) {
    double diff_original = 0.0;
    for (int i = 0; i < n1; i++) {
        diff_original += data1[i];
    }
    diff_original /= n1;
    for (int i = 0; i < n2; i++) {
        diff_original -= data2[i];
    }
    diff_original /= n2;

    double *combined = (double *)malloc((n1 + n2) * sizeof(double));
    for (int i = 0; i < n1; i++) {
        combined[i] = data1[i];
    }
    for (int i = 0; i < n2; i++) {
        combined[n1 + i] = data2[i];
    }

    double p_value = 1.0;
    for (int i = 0; i < iterations; i++) {
        for (int j = 0; j < n1 + n2; j++) {
            int k = j + rand() % (n1 + n2 - j);
            double temp = combined[j];
            combined[j] = combined[k];
            combined[k] = temp;
        }
        int split = rand() % (n1 + n2);
        double diff_perm = 0.0;
        for (int j = 0; j < split; j++) {
            diff_perm += combined[j];
        }
        diff_perm /= split;
        for (int j = split; j < n1 + n2; j++) {
            diff_perm -= combined[j];
        }
        diff_perm /= n1 + n2 - split;
        p_value += diff_perm >= diff_original;
    }

    free(combined);
    return p_value / (iterations + 1);
}

void non_terminating_permutations() {
    double data1[100], data2[100];
    for (int i = 0; i < 100; i++) {
        data1[i] = randn();
        data2[i] = 0.5 + randn();
    }
    while (1) {
        double p = permute_pvalue(data1, data2, 100, 100, ITERATIONS);
        printf("P-value: %f\n", p);
    }
}

double randn() {
    static double V1, V2, S;
    static int phase = 0;
    double X;

    if (phase == 0) {
        do {
            double U1 = (double)rand() / RAND_MAX;
            double U2 = (double)rand() / RAND_MAX;

            V1 = 2 * U1 - 1;
            V2 = 2 * U2 - 1;
            S = V1 * V1 + V2 * V2;
        } while (S >= 1 || S == 0);

        X = V1 * sqrt(-2 * log(S) / S);
    } else
        X = V2 * sqrt(-2 * log(S) / S);

    phase = 1 - phase;

    return X;
}

int main() {
    srand(time(NULL));
    non_terminating_permutations();
    return 0;
}