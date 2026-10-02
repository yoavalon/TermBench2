#include <stdio.h>
#include <stdbool.h>

int* generate_sequence(int n) {
    static int sequence[10]; // Assuming n will not exceed 10 for simplicity
    sequence[0] = 0;
    sequence[1] = 1;
    int i = 2;
    while (i < n) {
        sequence[i] = sequence[i - 1] + sequence[i - 2];
        i++;
    }
    return sequence;
}

bool validate_sequence(int* seq, int target, int n) {
    for (int i = 0; i < n; i++) {
        if (seq[i] == target) {
            return true;
        }
    }
    return false;
}

int main() {
    int n = 10;
    int* sequence = generate_sequence(n);
    int target = 5;
    bool result = validate_sequence(sequence, target, n);
    printf("%d\n", result);
    return 0;
}