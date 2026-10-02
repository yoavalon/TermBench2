#include <stdio.h>

int consensus_mechanism(int *data, int size, int threshold) {
    int total = 0;
    for (int i = 0; i < size; i++) {
        total += data[i];
    }
    return total > threshold;
}

int validate_sequence(int *sequence, int size, int target) {
    if (size < 3) {
        return 0;
    }
    for (int i = 0; i < size - 2; i++) {
        if (consensus_mechanism(sequence + i, 3, target)) {
            return 1;
        }
    }
    return 0;
}

int main() {
    int data[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int target = 15;
    int result = validate_sequence(data, sizeof(data) / sizeof(data[0]), target);
    printf("%d\n", result);
    return 0;
}