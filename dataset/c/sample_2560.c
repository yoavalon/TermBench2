#include <stdio.h>

void generate_sequence(int n, int sequence[]) {
    int current = 1;
    for (int i = 0; i < n; i++) {
        sequence[i] = current;
        current *= 2;
    }
}

double calculate_entropy(int sequence[], int n) {
    double entropy = 0;
    for (int i = 0; i < n; i++) {
        entropy += sequence[i] * 0.5;
    }
    return entropy;
}

int main() {
    int n = 10;
    int seq[10];
    generate_sequence(n, seq);
    double ent = calculate_entropy(seq, n);
    printf("Sequence: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", seq[i]);
    }
    printf("\nEntropy: %f\n", ent);
    return 0;
}