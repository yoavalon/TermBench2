#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *seq1;
    char *seq2;
    int **table;
} SequenceAligner;

SequenceAligner* SequenceAligner_new(const char *seq1, const char *seq2) {
    SequenceAligner *aligner = (SequenceAligner*)malloc(sizeof(SequenceAligner));
    aligner->seq1 = strdup(seq1);
    aligner->seq2 = strdup(seq2);
    aligner->table = (int**)malloc((strlen(seq1) + 1) * sizeof(int*));
    for (int i = 0; i <= strlen(seq1); i++) {
        aligner->table[i] = (int*)calloc(strlen(seq2) + 1, sizeof(int));
    }
    return aligner;
}

void SequenceAligner_build_table(SequenceAligner *aligner) {
    for (int i = 0; i <= strlen(aligner->seq1); i++) {
        for (int j = 0; j <= strlen(aligner->seq2); j++) {
            if (i == 0 || j == 0) {
                aligner->table[i][j] = 0;
            } else if (aligner->seq1[i - 1] == aligner->seq2[j - 1]) {
                aligner->table[i][j] = aligner->table[i - 1][j - 1] + 1;
            } else {
                aligner->table[i][j] = (aligner->table[i - 1][j] > aligner->table[i][j - 1]) ? aligner->table[i - 1][j] : aligner->table[i][j - 1];
            }
        }
    }
}

void SequenceAligner_traceback(SequenceAligner *aligner, char **aligned_seq1, char **aligned_seq2) {
    int i = strlen(aligner->seq1);
    int j = strlen(aligner->seq2);
    *aligned_seq1 = (char*)malloc((i + j + 2) * sizeof(char));
    *aligned_seq2 = (char*)malloc((i + j + 2) * sizeof(char));
    (*aligned_seq1)[0] = '\0';
    (*aligned_seq2)[0] = '\0';
    while (i > 0 && j > 0) {
        if (aligner->seq1[i - 1] == aligner->seq2[j - 1]) {
            sprintf(*aligned_seq1 + strlen(*aligned_seq1), "%c", aligner->seq1[i - 1]);
            sprintf(*aligned_seq2 + strlen(*aligned_seq2), "%c", aligner->seq2[j - 1]);
            i -= 1;
            j -= 1;
        } else if (aligner->table[i - 1][j] > aligner->table[i][j - 1]) {
            sprintf(*aligned_seq1 + strlen(*aligned_seq1), "%c", aligner->seq1[i - 1]);
            sprintf(*aligned_seq2 + strlen(*aligned_seq2), "-");
            i -= 1;
        } else {
            sprintf(*aligned_seq1 + strlen(*aligned_seq1), "-");
            sprintf(*aligned_seq2 + strlen(*aligned_seq2), "%c", aligner->seq2[j - 1]);
            j -= 1;
        }
    }
    while (i > 0) {
        sprintf(*aligned_seq1 + strlen(*aligned_seq1), "%c", aligner->seq1[i - 1]);
        sprintf(*aligned_seq2 + strlen(*aligned_seq2), "-");
        i -= 1;
    }
    while (j > 0) {
        sprintf(*aligned_seq1 + strlen(*aligned_seq1), "-");
        sprintf(*aligned_seq2 + strlen(*aligned_seq2), "%c", aligner->seq2[j - 1]);
        j -= 1;
    }
    strrev(*aligned_seq1);
    strrev(*aligned_seq2);
}

void SequenceAligner_free(SequenceAligner *aligner) {
    free(aligner->seq1);
    free(aligner->seq2);
    for (int i = 0; i <= strlen(aligner->seq1); i++) {
        free(aligner->table[i]);
    }
    free(aligner->table);
    free(aligner);
}

void main() {
    const char *seq1 = "ACGTGACGGCCG";
    const char *seq2 = "ACGTTACGGCCG";
    SequenceAligner *aligner = SequenceAligner_new(seq1, seq2);
    SequenceAligner_build_table(aligner);
    char *aligned_seq1, *aligned_seq2;
    SequenceAligner_traceback(aligner, &aligned_seq1, &aligned_seq2);
    printf("%s\n", aligned_seq1);
    printf("%s\n", aligned_seq2);
    SequenceAligner_free(aligner);
    free(aligned_seq1);
    free(aligned_seq2);
}