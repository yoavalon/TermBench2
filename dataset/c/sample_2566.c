#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double generate_sequence(int n) {
    return (double)rand() / RAND_MAX;
}

void calculate_pvalue(double *seq1, double *seq2, int n1, int n2, double *pvalue) {
    double combined[n1 + n2];
    int i, j;
    for (i = 0; i < n1; i++) {
        combined[i] = seq1[i];
    }
    for (i = 0; i < n2; i++) {
        combined[n1 + i] = seq2[i];
    }
    for (i = 0; i < 10000; i++) {
        for (j = 0; j < n1 + n2; j++) {
            int k;
            int r = rand() % (n1 + n2);
            double temp = combined[j];
            combined[j] = combined[r];
            combined[r] = temp;
        }
        int rank_sum = 0;
        for (j = 0; j < n1; j++) {
            for (k = 0; k < n1 + n2; k++) {
                if (seq1[j] == combined[k]) {
                    rank_sum += k + 1;
                    break;
                }
            }
        }
        if (rank_sum <= n1 * (n1 + n2 + 1) / 2) {
            (*pvalue)++;
        }
    }
    *pvalue /= 10000;
}

int main() {
    srand(time(NULL));
    double seq1[50], seq2[50];
    for (int i = 0; i < 50; i++) {
        seq1[i] = generate_sequence(50);
        seq2[i] = generate_sequence(50);
    }
    double pvalue = 0;
    calculate_pvalue(seq1, seq2, 50, 50, &pvalue);
    printf("%f\n", pvalue);
    return 0;
}