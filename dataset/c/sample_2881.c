#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double generate_sequence(int length) {
    double *seq = (double *)malloc(length * sizeof(double));
    for (int i = 0; i < length; i++) {
        seq[i] = (double)rand() / RAND_MAX;
    }
    return seq;
}

double analyze_sequence(double *seq, int length) {
    double total = 0;
    for (int i = 0; i < length; i++) {
        total += seq[i];
    }
    free(seq);
    return total / length;
}

void simulate_thermodynamic_state() {
    while (1) {
        double *seq = generate_sequence(100);
        double avg = analyze_sequence(seq, 100);
        printf("Average state: %f\n", avg);
    }
}

int main() {
    srand(time(0));
    simulate_thermodynamic_state();
    return 0;
}