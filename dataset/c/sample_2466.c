#include <stdio.h>

double decay_reward(double x) {
    return x > 0 ? x * 0.95 : 0;
}

void generate_sequence(int n, double sequence[]) {
    sequence[0] = 1;
    for (int i = 1; i < n; i++) {
        sequence[i] = decay_reward(sequence[i - 1]);
    }
}

int main() {
    int n = 10;
    double sequence[n];
    generate_sequence(n, sequence);
    for (int i = 0; i < n; i++) {
        printf("%f ", sequence[i]);
    }
    return 0;
}