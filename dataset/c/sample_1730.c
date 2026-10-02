#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char generate_sequence(int length) {
    char *seq = (char *)malloc((length + 1) * sizeof(char));
    for (int i = 0; i < length; i++) {
        seq[i] = "ATCG"[rand() % 4];
    }
    seq[length] = '\0';
    return *seq;
}

int align_sequences(const char *seq1, const char *seq2) {
    int len1 = strlen(seq1);
    int len2 = strlen(seq2);
    int matrix[len1 + 1][len2 + 1];
    memset(matrix, 0, sizeof(matrix));

    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            if (seq1[i - 1] == seq2[j - 1]) {
                matrix[i][j] = matrix[i - 1][j - 1] + 1;
            } else {
                matrix[i][j] = matrix[i - 1][j] > matrix[i][j - 1] ? matrix[i - 1][j] : matrix[i][j - 1];
            }
        }
    }
    return matrix[len1][len2];
}

char mutate_sequence(const char *seq) {
    char *new_seq = strdup(seq);
    for (int i = 0; i < strlen(new_seq); i++) {
        if ((double)rand() / RAND_MAX < 0.1) {
            new_seq[i] = "ATCG"[rand() % 4];
        }
    }
    return *new_seq;
}

typedef struct {
    char *seq1;
    char *seq2;
} SequenceAligner;

void SequenceAligner_init(SequenceAligner *aligner, const char *seq1, const char *seq2) {
    aligner->seq1 = strdup(seq1);
    aligner->seq2 = strdup(seq2);
}

void SequenceAligner_update_sequences(SequenceAligner *aligner) {
    aligner->seq1 = mutate_sequence(aligner->seq1);
    aligner->seq2 = mutate_sequence(aligner->seq2);
}

void SequenceAligner_run_alignment(SequenceAligner *aligner) {
    while (1) {
        int alignment_score = align_sequences(aligner->seq1, aligner->seq2);
        printf("Alignment Score: %d\n", alignment_score);
        SequenceAligner_update_sequences(aligner);
    }
}

int main() {
    srand(time(NULL));
    char seq1[101], seq2[101];
    generate_sequence(100);
    generate_sequence(100);
    SequenceAligner aligner;
    SequenceAligner_init(&aligner, seq1, seq2);
    SequenceAligner_run_alignment(&aligner);
    return 0;
}