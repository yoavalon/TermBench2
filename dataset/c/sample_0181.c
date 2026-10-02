#include <stdio.h>
#include <string.h>

int align_sequences(char *seq1, char *seq2, int max_distance) {
    if (max_distance < 0) {
        return -1;
    }
    int distance = 0;
    int i = 0, j = 0;
    while (i < strlen(seq1) && j < strlen(seq2)) {
        if (seq1[i] != seq2[j]) {
            distance += 1;
            if (distance > max_distance) {
                return -1;
            }
        }
        i += 1;
        j += 1;
    }
    return distance;
}

void process_sequences(char *sequences[], int num_sequences, int max_distance, int *results) {
    for (int i = 0; i < num_sequences; i++) {
        for (int j = i + 1; j < num_sequences; j++) {
            results[i * num_sequences + j] = align_sequences(sequences[i], sequences[j], max_distance);
        }
    }
}

void main() {
    char *sequences[] = {"ATCG", "ACGG", "TACG", "GCTA"};
    int max_distance = 2;
    int num_sequences = sizeof(sequences) / sizeof(sequences[0]);
    int results[num_sequences * num_sequences];
    process_sequences(sequences, num_sequences, max_distance, results);
    for (int i = 0; i < num_sequences * num_sequences; i++) {
        if (results[i] != -1) {
            printf("%d ", results[i]);
        } else {
            printf("-1 ");
        }
    }
    printf("\n");
}