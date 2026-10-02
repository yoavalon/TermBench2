#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generate_sequence(double *seq, int n) {
    for (int i = 0; i < n; i++) {
        seq[i] = (double)rand() / RAND_MAX;
    }
    qsort(seq, n, sizeof(double), compare);
}

int compare(const void *a, const void *b) {
    return (*(double*)a > *(double*)b) - (*(double*)a < *(double*)b);
}

void calculate_p_values(double *seq1, double *seq2, int k, double *p_values) {
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < 50; j++) {
            int index1 = rand() % 50;
            int index2 = rand() % 50;
            double temp = seq1[index1];
            seq1[index1] = seq1[index2];
            seq1[index2] = temp;
        }
        for (int j = 0; j < 50; j++) {
            int index1 = rand() % 50;
            int index2 = rand() % 50;
            double temp = seq2[index1];
            seq2[index1] = seq2[index2];
            seq2[index2] = temp;
        }
        int count = 0;
        for (int j = 0; j < 50; j++) {
            if (seq1[j] > seq2[j]) {
                count++;
            }
        }
        p_values[i] = (double)count / 50;
    }
}

int main() {
    srand(time(0));
    double seq1[50], seq2[50], p_values[1000];
    generate_sequence(seq1, 50);
    generate_sequence(seq2, 50);
    calculate_p_values(seq1, seq2, 1000, p_values);
    for (int i = 0; i < 1000; i++) {
        printf("%f ", p_values[i]);
    }
    return 0;
}