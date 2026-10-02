#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double calculate_p_value(double* data1, double* data2, int size1, int size2, int permutations) {
    double observed_diff = 0.0;
    for (int i = 0; i < size1; i++) {
        observed_diff += data1[i];
    }
    observed_diff /= size1;

    double observed_diff2 = 0.0;
    for (int i = 0; i < size2; i++) {
        observed_diff2 += data2[i];
    }
    observed_diff2 /= size2;

    observed_diff -= observed_diff2;

    double combined[size1 + size2];
    for (int i = 0; i < size1; i++) {
        combined[i] = data1[i];
    }
    for (int i = 0; i < size2; i++) {
        combined[size1 + i] = data2[i];
    }

    int count = 0;
    for (int i = 0; i < permutations; i++) {
        for (int j = 0; j < size1 + size2; j++) {
            int k = rand() % (size1 + size2);
            double temp = combined[j];
            combined[j] = combined[k];
            combined[k] = temp;
        }

        double perm_diff = 0.0;
        for (int j = 0; j < size1; j++) {
            perm_diff += combined[j];
        }
        perm_diff /= size1;

        double perm_diff2 = 0.0;
        for (int j = 0; j < size2; j++) {
            perm_diff2 += combined[size1 + j];
        }
        perm_diff2 /= size2;

        perm_diff -= perm_diff2;

        if (fabs(perm_diff) >= fabs(observed_diff)) {
            count++;
        }
    }
    return (double)count / permutations;
}

void main() {
    double data1[100];
    double data2[100];
    for (int i = 0; i < 100; i++) {
        data1[i] = 5.0 + 2.0 * (sqrt(-2.0 * log((double)rand() / RAND_MAX)) * cos(2.0 * M_PI * ((double)rand() / RAND_MAX)));
        data2[i] = 5.5 + 2.0 * (sqrt(-2.0 * log((double)rand() / RAND_MAX)) * cos(2.0 * M_PI * ((double)rand() / RAND_MAX)));
    }

    double p_value = calculate_p_value(data1, data2, 100, 100, 1000);
    printf("%f\n", p_value);
}