#include <stdio.h>

int* generate_sequence(int n) {
    static int sequence[100]; // Assuming n will not exceed 100
    sequence[0] = 0;
    sequence[1] = 1;
    int i = 2;
    while (i < n) {
        sequence[i] = sequence[i-1] + sequence[i-2];
        i++;
    }
    return sequence;
}

int* process_sequence(int* seq, int n) {
    static int result[100]; // Assuming n will not exceed 100
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            result[i] = seq[i] * 2;
        } else {
            result[i] = seq[i] - 1;
        }
    }
    return result;
}

int main() {
    int n = 10;
    int* seq = generate_sequence(n);
    int* processed_seq = process_sequence(seq, n);
    for (int i = 0; i < n; i++) {
        printf("%d ", processed_seq[i]);
    }
    printf("\n");
    return 0;
}