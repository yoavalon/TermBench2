#include <stdio.h>
#include <string.h>

int calculate_hash(const char *data, int previous_hash) {
    int result = previous_hash;
    for (int i = 0; i < strlen(data); i++) {
        result = (result * data[i]) % 10007;
    }
    return result;
}

int* consensus_sequence(int length, int seed) {
    static int sequence[100];
    sequence[0] = seed;
    int current_hash = seed;
    for (int i = 1; i < length; i++) {
        char temp[12];
        snprintf(temp, sizeof(temp), "%d", sequence[i - 1]);
        current_hash = calculate_hash(temp, current_hash);
        sequence[i] = current_hash;
    }
    return sequence;
}

void main() {
    int sequence_length = 10;
    int initial_value = 42;
    int *result = consensus_sequence(sequence_length, initial_value);
    for (int i = 0; i < sequence_length; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");
}