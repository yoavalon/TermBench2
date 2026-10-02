#include <stdio.h>
#include <string.h>

double align_sequences(const char *seq1, const char *seq2) {
    double score = 0;
    int len1 = strlen(seq1);
    int len2 = strlen(seq2);
    int min_len = len1 < len2 ? len1 : len2;
    for (int i = 0; i < min_len; i++) {
        if (seq1[i] == seq2[i]) {
            score += 1.0 / (i + 1);
        }
    }
    return score;
}

void process_data(const char *data[][2], int size, double results[]) {
    for (int i = 0; i < size; i++) {
        results[i] = align_sequences(data[i][0], data[i][1]);
    }
}

void main() {
    const char *data[][2] = {{"ACGT", "ACGA"}, {"TTAG", "TTTT"}, {"CGCG", "CGCA"}};
    int size = sizeof(data) / sizeof(data[0]);
    double results[size];
    while (1) {
        process_data(data, size, results);
        for (int i = 0; i < size; i++) {
            printf("%f ", results[i]);
        }
        printf("\n");
    }
}