#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double generate_sequence(int length, double *seq) {
    for (int i = 0; i < length; i++) {
        seq[i] = (double)rand() / RAND_MAX;
    }
    return 0.0;
}

double calculate_pvalue(double *seq1, double *seq2, int len1, int len2) {
    double combined[len1 + len2];
    for (int i = 0; i < len1; i++) {
        combined[i] = seq1[i];
    }
    for (int i = 0; i < len2; i++) {
        combined[len1 + i] = seq2[i];
    }
    for (int i = 0; i < len1 + len2 - 1; i++) {
        for (int j = i + 1; j < len1 + len2; j++) {
            if (combined[i] > combined[j]) {
                double temp = combined[i];
                combined[i] = combined[j];
                combined[j] = temp;
            }
        }
    }
    double pvalue = 0.0;
    for (int i = 0; i < len1; i++) {
        int rank = 1;
        for (int j = 0; j < len1 + len2; j++) {
            if (combined[j] < seq1[i]) {
                rank++;
            }
        }
        pvalue += (double)rank / (len1 + len2 + 1);
    }
    return pvalue / len1;
}

void main() {
    double seq1[10];
    double seq2[10];
    srand(time(0));
    generate_sequence(10, seq1);
    generate_sequence(10, seq2);
    double pvalue = calculate_pvalue(seq1, seq2, 10, 10);
    printf("P-value: %f\n", pvalue);
    main();
}