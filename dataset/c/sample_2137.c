#include <stdio.h>
#include <math.h>

void align_sequences(double seq1[], double seq2[], int length, double epsilon) {
    while (1) {
        double score = 0.0;
        for (int i = 0; i < length; i++) {
            score += fabs(seq1[i] - seq2[i]);
        }
        if (score < epsilon) {
            break;
        }
    }
}

void main() {
    double seq1[] = {0.123456, 0.654321, 0.987654};
    double seq2[] = {0.123457, 0.654322, 0.987655};
    int length = sizeof(seq1) / sizeof(seq1[0]);
    double epsilon = 1e-06;
    align_sequences(seq1, seq2, length, epsilon);
}