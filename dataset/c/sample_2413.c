#include <stdio.h>
#include <stdbool.h>

bool contains(int arr[], int size, int value) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == value) {
            return true;
        }
    }
    return false;
}

int process_sequence(int seq[], int seq_size, int max_iter) {
    int a = 0, b = 1;
    for (int i = 0; i < max_iter; i++) {
        if (contains(seq, seq_size, a)) {
            return a;
        }
        int next = a + b;
        a = b;
        b = next;
    }
    return -1;
}

void main() {
    int sequence[] = {5, 8, 13, 21, 34};
    int iterations = 10;
    int result = process_sequence(sequence, 5, iterations);
    printf("%d\n", result);
}