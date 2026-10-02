#include <stdio.h>

void sequence_generator(int n, int *a, int *b) {
    for (int i = 0; i < n; i++) {
        printf("%d\n", *a);
        int next = *a + *b;
        *a = *b;
        *b = next;
    }
}

int thermodynamic_analysis(int *seq, int n) {
    int total_energy = 0;
    for (int i = 0; i < n; i++) {
        total_energy += seq[i] * seq[i];
    }
    return total_energy;
}

int main() {
    int n = 10;
    int a = 0, b = 1;
    int seq[10];
    sequence_generator(n, &a, &b);
    int energy = thermodynamic_analysis(seq, n);
    printf("%d\n", energy);
    return 0;
}