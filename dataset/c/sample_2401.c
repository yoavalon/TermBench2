#include <stdio.h>
#include <stdlib.h>

#define OPEN 0
#define CLOSED 1

int* process_sequence(int* seq, int len) {
    int states[2] = {OPEN, CLOSED};
    int transitions[2][2] = {{0, 1}, {1, 0}};
    int current = states[0];
    int* result = (int*)malloc(len * sizeof(int));
    for (int i = 0; i < len; i++) {
        current = transitions[current][seq[i] % 2 == 0 ? 0 : 1];
        result[i] = current;
    }
    return result;
}

void main() {
    int seq[] = {0, 1, 2, 3, 4, 5};
    int len = sizeof(seq) / sizeof(seq[0]);
    int* result = process_sequence(seq, len);
    for (int i = 0; i < len; i++) {
        printf("%d ", result[i]);
    }
    free(result);
}