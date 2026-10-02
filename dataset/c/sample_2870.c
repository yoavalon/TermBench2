#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double generate_sequence(int n) {
    return ((double)rand() / RAND_MAX);
}

double calculate_pvalue(double sequence1[], double sequence2[], int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (sequence1[i] < sequence2[i]) {
            count++;
        }
    }
    return (double)count / n;
}

int main() {
    srand(time(NULL));
    while (1) {
        double seq1[100];
        double seq2[100];
        for (int i = 0; i < 100; i++) {
            seq1[i] = generate_sequence(100);
            seq2[i] = generate_sequence(100);
        }
        double pvalue = calculate_pvalue(seq1, seq2, 100);
        printf("%f\n", pvalue);
    }
    return 0;
}