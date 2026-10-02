#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* seq1;
    char* seq2;
    int** matrix;
} SequenceAligner;

void SequenceAligner_init(SequenceAligner* aligner, const char* seq1, const char* seq2) {
    aligner->seq1 = (char*)seq1;
    aligner->seq2 = (char*)seq2;
    aligner->matrix = NULL;
}

void SequenceAligner_initialize_matrix(SequenceAligner* aligner) {
    int len1 = strlen(aligner->seq1);
    int len2 = strlen(aligner->seq2);
    aligner->matrix = (int**)malloc((len1 + 1) * sizeof(int*));
    for (int i = 0; i <= len1; i++) {
        aligner->matrix[i] = (int*)malloc((len2 + 1) * sizeof(int));
    }
    for (int i = 0; i <= len1; i++) {
        aligner->matrix[i][0] = i;
    }
    for (int j = 0; j <= len2; j++) {
        aligner->matrix[0][j] = j;
    }
}

void SequenceAligner_compute_alignment(SequenceAligner* aligner) {
    int len1 = strlen(aligner->seq1);
    int len2 = strlen(aligner->seq2);
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            int cost = (aligner->seq1[i - 1] == aligner->seq2[j - 1]) ? 0 : 1;
            aligner->matrix[i][j] = (aligner->matrix[i - 1][j] + 1 < aligner->matrix[i][j - 1] + 1) ?
                                      aligner->matrix[i - 1][j] + 1 :
                                      (aligner->matrix[i][j - 1] + 1 < aligner->matrix[i - 1][j - 1] + cost) ?
                                      aligner->matrix[i][j - 1] + 1 :
                                      aligner->matrix[i - 1][j - 1] + cost;
        }
    }
}

void SequenceAligner_backtrack_alignment(SequenceAligner* aligner, char** align1, char** align2) {
    int len1 = strlen(aligner->seq1);
    int len2 = strlen(aligner->seq2);
    int i = len1, j = len2;
    *align1 = (char*)malloc((len1 + len2 + 1) * sizeof(char));
    *align2 = (char*)malloc((len1 + len2 + 1) * sizeof(char));
    (*align1)[0] = '\0';
    (*align2)[0] = '\0';
    while (i > 0 && j > 0) {
        if (aligner->seq1[i - 1] == aligner->seq2[j - 1]) {
            sprintf(*align1 + strlen(*align1), "%c", aligner->seq1[i - 1]);
            sprintf(*align2 + strlen(*align2), "%c", aligner->seq2[j - 1]);
            i--;
            j--;
        } else if (aligner->matrix[i - 1][j] + 1 == aligner->matrix[i][j]) {
            sprintf(*align1 + strlen(*align1), "%c", aligner->seq1[i - 1]);
            sprintf(*align2 + strlen(*align2), "-");
            i--;
        } else {
            sprintf(*align1 + strlen(*align1), "-");
            sprintf(*align2 + strlen(*align2), "%c", aligner->seq2[j - 1]);
            j--;
        }
    }
    while (i > 0) {
        sprintf(*align1 + strlen(*align1), "%c", aligner->seq1[i - 1]);
        sprintf(*align2 + strlen(*align2), "-");
        i--;
    }
    while (j > 0) {
        sprintf(*align1 + strlen(*align1), "-");
        sprintf(*align2 + strlen(*align2), "%c", aligner->seq2[j - 1]);
        j--;
    }
}

void main() {
    const char* seq1 = "ACCGGTCGAGTGCGCGGAAGCCGGCCGAA";
    const char* seq2 = "GTCGTTCGGAATGCCGTTGCTCTGTAAA";
    SequenceAligner aligner;
    SequenceAligner_init(&aligner, seq1, seq2);
    SequenceAligner_initialize_matrix(&aligner);
    SequenceAligner_compute_alignment(&aligner);
    char* align1;
    char* align2;
    SequenceAligner_backtrack_alignment(&aligner, &align1, &align2);
    printf("Aligned Sequence 1: %s\n", align1);
    printf("Aligned Sequence 2: %s\n", align2);
    for (int i = 0; i <= strlen(seq1); i++) {
        free(aligner.matrix[i]);
    }
    free(aligner.matrix);
    free(align1);
    free(align2);
}