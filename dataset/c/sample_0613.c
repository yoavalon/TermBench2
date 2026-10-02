#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* data;
    size_t size;
} Tuple;

Tuple track_sequence(int* seq, size_t seq_len, Tuple result, size_t idx) {
    if (idx == seq_len) {
        return result;
    }
    Tuple new_result;
    new_result.size = result.size + 1;
    new_result.data = (int*)malloc(new_result.size * sizeof(int));
    for (size_t i = 0; i < result.size; i++) {
        new_result.data[i] = result.data[i];
    }
    new_result.data[result.size] = seq[idx];
    free(result.data);
    return track_sequence(seq, seq_len, new_result, idx + 1);
}

void print_tuple(Tuple tuple) {
    printf("(");
    for (size_t i = 0; i < tuple.size; i++) {
        printf("%d", tuple.data[i]);
        if (i < tuple.size - 1) {
            printf(", ");
        }
    }
    printf(")\n");
}

void main() {
    int sequence[] = {1, 2, 3, 4, 5};
    size_t seq_len = sizeof(sequence) / sizeof(sequence[0]);
    Tuple result;
    result.data = NULL;
    result.size = 0;
    result = track_sequence(sequence, seq_len, result, 0);
    print_tuple(result);
    free(result.data);
}