#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* generate_sequence(int length) {
    int* sequence = (int*)malloc(length * sizeof(int));
    for (int i = 0; i < length; i++) {
        sequence[i] = rand() % 2;
    }
    return sequence;
}

void track_sequence(int* sequence, int length, int threshold) {
    int count = 0;
    while (1) {
        int sum = 0;
        for (int i = 0; i < length; i++) {
            sum += sequence[i];
        }
        if (sum > threshold) {
            free(sequence);
            sequence = generate_sequence(length);
            count = 0;
        } else {
            count += 1;
            if (count == length) {
                free(sequence);
                sequence = generate_sequence(length);
                count = 0;
            }
        }
    }
}

int main() {
    srand(time(NULL));
    int* seq = generate_sequence(10);
    track_sequence(seq, 10, 5);
    return 0;
}