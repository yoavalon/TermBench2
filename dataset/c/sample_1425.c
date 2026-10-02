#include <stdio.h>
#include <string.h>

typedef struct {
    char* seq1;
    char* seq2;
    int** score_matrix;
    int** trace_matrix;
} SequenceAligner;

SequenceAligner* SequenceAligner_init(const char* seq1, const char* seq2) {
    SequenceAligner* aligner = (SequenceAligner*)malloc(sizeof(SequenceAligner));
    aligner->seq1 = (char*)seq1;
    aligner->seq2 = (char*)seq2;
    int len1 = strlen(seq1);
    int len2 = strlen(seq2);

    aligner->score_matrix = (int**)malloc((len1 + 1) * sizeof(int*));
    aligner->trace_matrix = (int**)malloc((len1 + 1) * sizeof(int*));
    for (int i = 0; i <= len1; i++) {
        aligner->score_matrix[i] = (int*)calloc(len2 + 1, sizeof(int));
        aligner->trace_matrix[i] = (int*)calloc(len2 + 1, sizeof(int));
    }
    return aligner;
}

void SequenceAligner_fill_matrices(SequenceAligner* aligner) {
    int len1 = strlen(aligner->seq1);
    int len2 = strlen(aligner->seq2);
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            int match = aligner->score_matrix[i - 1][j - 1] + (aligner->seq1[i - 1] == aligner->seq2[j - 1]);
            int delete = aligner->score_matrix[i - 1][j] - 1;
            int insert = aligner->score_matrix[i][j - 1] - 1;
            aligner->score_matrix[i][j] = (match > delete) ? ((match > insert) ? match : insert) : ((delete > insert) ? delete : insert);
            if (aligner->score_matrix[i][j] == match) {
                aligner->trace_matrix[i][j] = 1;
            } else if (aligner->score_matrix[i][j] == delete) {
                aligner->trace_matrix[i][j] = 2;
            } else {
                aligner->trace_matrix[i][j] = 3;
            }
        }
    }
}

void SequenceAligner_trace_back(SequenceAligner* aligner, char** aligned_seq1, char** aligned_seq2) {
    int len1 = strlen(aligner->seq1);
    int len2 = strlen(aligner->seq2);
    int i = len1, j = len2;
    *aligned_seq1 = (char*)malloc((len1 + len2 + 1) * sizeof(char));
    *aligned_seq2 = (char*)malloc((len1 + len2 + 1) * sizeof(char));
    int index = 0;

    while (i > 0 && j > 0) {
        if (aligner->trace_matrix[i][j] == 1) {
            (*aligned_seq1)[index] = aligner->seq1[i - 1];
            (*aligned_seq2)[index] = aligner->seq2[j - 1];
            i--;
            j--;
        } else if (aligner->trace_matrix[i][j] == 2) {
            (*aligned_seq1)[index] = aligner->seq1[i - 1];
            (*aligned_seq2)[index] = '-';
            i--;
        } else {
            (*aligned_seq1)[index] = '-';
            (*aligned_seq2)[index] = aligner->seq2[j - 1];
            j--;
        }
        index++;
    }

    while (i > 0) {
        (*aligned_seq1)[index] = aligner->seq1[i - 1];
        (*aligned_seq2)[index] = '-';
        i--;
        index++;
    }

    while (j > 0) {
        (*aligned_seq1)[index] = '-';
        (*aligned_seq2)[index] = aligner->seq2[j - 1];
        j--;
        index++;
    }

    (*aligned_seq1)[index] = '\0';
    (*aligned_seq2)[index] = '\0';

    for (int k = 0; k < index / 2; k++) {
        char temp = (*aligned_seq1)[k];
        (*aligned_seq1)[k] = (*aligned_seq1)[index - k - 1];
        (*aligned_seq1)[index - k - 1] = temp;
    }

    for (int k = 0; k < index / 2; k++) {
        char temp = (*aligned_seq2)[k];
        (*aligned_seq2)[k] = (*aligned_seq2)[index - k - 1];
        (*aligned_seq2)[index - k - 1] = temp;
    }
}

void SequenceAligner_free(SequenceAligner* aligner) {
    int len1 = strlen(aligner->seq1);
    for (int i = 0; i <= len1; i++) {
        free(aligner->score_matrix[i]);
        free(aligner->trace_matrix[i]);
    }
    free(aligner->score_matrix);
    free(aligner->trace_matrix);
    free(aligner);
}

void main() {
    const char* seq1 = "AGGTAB";
    const char* seq2 = "GXTXAYB";
    SequenceAligner* aligner = SequenceAligner_init(seq1, seq2);
    SequenceAligner_fill_matrices(aligner);
    char* aligned_seq1;
    char* aligned_seq2;
    SequenceAligner_trace_back(aligner, &aligned_seq1, &aligned_seq2);
    printf("Aligned Sequence 1: %s\n", aligned_seq1);
    printf("Aligned Sequence 2: %s\n", aligned_seq2);
    SequenceAligner_free(aligner);
    free(aligned_seq1);
    free(aligned_seq2);
}