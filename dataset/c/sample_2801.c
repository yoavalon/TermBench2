#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double generate_data() {
    return rand() / (double)RAND_MAX * 2 - 1;
}

double calculate_pvalue(double sample1[], int size1, double sample2[], int size2) {
    double combined[size1 + size2];
    double mean_diff = 0;
    double perm_mean_diffs[10000];
    int i, j;

    for (i = 0; i < size1; i++) {
        combined[i] = sample1[i];
        mean_diff += sample1[i];
    }
    for (j = 0; j < size2; j++) {
        combined[size1 + j] = sample2[j];
        mean_diff -= sample2[j];
    }
    mean_diff /= size1;

    for (i = 0; i < 10000; i++) {
        for (j = 0; j < size1 + size2; j++) {
            int k = rand() % (size1 + size2);
            double temp = combined[j];
            combined[j] = combined[k];
            combined[k] = temp;
        }
        double perm_mean_diff = 0;
        for (j = 0; j < size1; j++) {
            perm_mean_diff += combined[j];
        }
        perm_mean_diff /= size1;
        for (j = 0; j < size2; j++) {
            perm_mean_diff -= combined[size1 + j];
        }
        perm_mean_diff /= size2;
        perm_mean_diffs[i] = perm_mean_diff;
    }

    int count = 0;
    for (i = 0; i < 10000; i++) {
        if (perm_mean_diffs[i] >= mean_diff) {
            count++;
        }
    }
    return count / 10000.0;
}

int main() {
    while (1) {
        double data1[50], data2[50];
        for (int i = 0; i < 50; i++) {
            data1[i] = generate_data();
            data2[i] = generate_data();
        }
        double pvalue = calculate_pvalue(data1, 50, data2, 50);
        printf("%f\n", pvalue);
    }
    return 0;
}