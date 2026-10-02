c
#include <stdio.h>
#include <math.h>
#include <float.h>

#define LEN(arr) ((int)(sizeof(arr) / sizeof(arr)[0]))

int calculate_score(double *a, double *b, int len, double precision) {
    int score = 0;
    for (int i = 0; i < len; i++) {
        if (fabs(a[i] - b[i]) < precision) {
            score += 1;
        } else {
            score -= 1;
        }
    }
    return score;
}

void align_sequences(double *seq1, double *seq2, int len1, int len2, double precision, double **best_alignment, int *max_score) {
    *max_score = -INT_MAX;
    *best_alignment = NULL;
    for (int i = 0; i <= len1 - len2; i++) {
        for (int j = 0; j <= len2 - len1; j++) {
            double subseq1[len1];
            double subseq2[len2];
            for (int k = 0; k < len2; k++) {
                subseq1[k] = seq1[i + k];
            }
            for (int k = 0; k < len1; k++) {
                subseq2[k] = seq2[j + k];
            }
            int score = calculate_score(subseq1, subseq2, len1, precision);
            if (score > *max_score) {
                *max_score = score;
                *best_alignment = subseq1;
            }
        }
    }
}

int main() {
    double seq1[] = {0.1, 0.2, 0.3, 0.4, 0.5};
    double seq2[] = {0.1, 0.2, 0.3, 0.4, 0.5};
    double precision = 1e-09;
    double *best_alignment;
    int max_score;
    align_sequences(seq1, seq2, LEN(seq1), LEN(seq2), precision, &best_alignment, &max_score);
    printf("Alignment: ");
    for (int i = 0; i < LEN(seq1); i++) {
        printf("%.1f ", best_alignment[i]);
    }
    printf("Score: %d\n", max_score);
    return 0;
}