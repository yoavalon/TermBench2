#include <stdio.h>
#include <string.h>

int align_sequences(const char *seq1, const char *seq2) {
    int len1 = strlen(seq1);
    int len2 = strlen(seq2);
    int matrix[len1 + 1][len2 + 1];
    for (int i = 0; i <= len1; i++) {
        for (int j = 0; j <= len2; j++) {
            matrix[i][j] = 0;
        }
    }
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            int match = matrix[i - 1][j - 1] + (seq1[i - 1] == seq2[j - 1]);
            int delete = matrix[i - 1][j] - 1;
            int insert = matrix[i][j - 1] - 1;
            matrix[i][j] = (match > delete) ? ((match > insert) ? match : insert) : ((delete > insert) ? delete : insert);
        }
    }
    return matrix[len1][len2];
}

void process_genomic_data(const char *data[], int *aligned_scores, int data_size) {
    for (int i = 0; i < data_size; i++) {
        const char *key = data[i];
        const char *sequence1 = data[i + 1];
        const char *sequence2 = data[i + 2];
        aligned_scores[i] = align_sequences(sequence1, sequence2);
        i += 2;
    }
}

void main() {
    const char *genomic_data[] = {
        "sample1", "ATCG", "ACGT",
        "sample2", "GGTC", "GTCA"
    };
    int aligned_scores[2];
    int data_size = sizeof(genomic_data) / sizeof(genomic_data[0]);
    process_genomic_data(genomic_data, aligned_scores, data_size);
    for (int i = 0; i < 2; i++) {
        printf("%s: %d\n", genomic_data[i * 3], aligned_scores[i]);
    }
}