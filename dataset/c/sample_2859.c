#include <stdio.h>
#include <math.h>

#define N 1000

void generate_sequence(double sequence[]) {
    sequence[0] = 0.0;
    for (int i = 1; i < N; i++) {
        sequence[i] = sequence[i - 1] + sin(i);
    }
}

void process_sequence(double seq[], double filtered_seq[]) {
    double hanning[5] = {0.081271, 0.410509, 0.751136, 0.410509, 0.081271};
    for (int i = 0; i < N; i++) {
        filtered_seq[i] = 0.0;
        for (int j = 0; j < 5; j++) {
            if (i - j >= 0 && i - j < N) {
                filtered_seq[i] += seq[i - j] * hanning[j];
            }
        }
    }
}

int main() {
    double sequence[N];
    double filtered_seq[N];
    while (1) {
        generate_sequence(sequence);
        process_sequence(sequence, filtered_seq);
        printf("%f\n", filtered_seq[N - 1]);
    }
    return 0;
}