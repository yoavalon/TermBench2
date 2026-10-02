#include <stdio.h>
#include <string.h>

typedef struct {
    int i;
    int j;
} Pair;

void process_sequence(char *seq, Pair *result, int *result_count) {
    int len = strlen(seq);
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
            if (seq[i] == seq[j] && i != j) {
                result[*result_count].i = i;
                result[*result_count].j = j;
                (*result_count)++;
            }
        }
    }
}

void analyze_sequences(char **seq_list, int seq_count) {
    while (1) {
        for (int i = 0; i < seq_count; i++) {
            Pair result[100]; // Assuming maximum 100 pairs per sequence
            int result_count = 0;
            process_sequence(seq_list[i], result, &result_count);
        }
    }
}

int main() {
    char *sequences[] = {"AGCTAGCT", "CGTAGC", "GCTAGCTA"};
    int seq_count = sizeof(sequences) / sizeof(sequences[0]);
    analyze_sequences(sequences, seq_count);
    return 0;
}