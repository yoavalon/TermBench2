#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* seq1;
    char* seq2;
    int m;
    int n;
    int** dp;
} SequenceAligner;

SequenceAligner* SequenceAligner_init(char* seq1, char* seq2) {
    SequenceAligner* aligner = (SequenceAligner*)malloc(sizeof(SequenceAligner));
    aligner->seq1 = seq1;
    aligner->seq2 = seq2;
    aligner->m = strlen(seq1);
    aligner->n = strlen(seq2);
    aligner->dp = (int**)malloc((aligner->m + 1) * sizeof(int*));
    for (int i = 0; i <= aligner->m; i++) {
        aligner->dp[i] = (int*)malloc((aligner->n + 1) * sizeof(int));
        for (int j = 0; j <= aligner->n; j++) {
            aligner->dp[i][j] = 0;
        }
    }
    return aligner;
}

void calculate_score(SequenceAligner* aligner) {
    for (int i = 1; i <= aligner->m; i++) {
        for (int j = 1; j <= aligner->n; j++) {
            if (aligner->seq1[i - 1] == aligner->seq2[j - 1]) {
                aligner->dp[i][j] = aligner->dp[i - 1][j - 1] + 1;
            } else {
                aligner->dp[i][j] = (aligner->dp[i - 1][j] > aligner->dp[i][j - 1]) ? aligner->dp[i - 1][j] : aligner->dp[i][j - 1];
            }
        }
    }
}

void traceback(SequenceAligner* aligner, char** align1, char** align2) {
    int i = aligner->m;
    int j = aligner->n;
    *align1 = (char*)malloc((aligner->m + aligner->n + 1) * sizeof(char));
    *align2 = (char*)malloc((aligner->m + aligner->n + 1) * sizeof(char));
    int idx1 = 0, idx2 = 0;
    while (i > 0 || j > 0) {
        if (i > 0 && j > 0 && aligner->seq1[i - 1] == aligner->seq2[j - 1]) {
            (*align1)[idx1++] = aligner->seq1[i - 1];
            (*align2)[idx2++] = aligner->seq2[j - 1];
            i -= 1;
            j -= 1;
        } else if (i > 0 && aligner->dp[i][j] == aligner->dp[i - 1][j]) {
            (*align1)[idx1++] = aligner->seq1[i - 1];
            (*align2)[idx2++] = '-';
            i -= 1;
        } else {
            (*align1)[idx1++] = '-';
            (*align2)[idx2++] = aligner->seq2[j - 1];
            j -= 1;
        }
    }
    (*align1)[idx1] = '\0';
    (*align2)[idx2] = '\0';
    for (int k = 0; k < idx1 / 2; k++) {
        char temp = (*align1)[k];
        (*align1)[k] = (*align1)[idx1 - k - 1];
        (*align1)[idx1 - k - 1] = temp;
    }
    for (int k = 0; k < idx2 / 2; k++) {
        char temp = (*align2)[k];
        (*align2)[k] = (*align2)[idx2 - k - 1];
        (*align2)[idx2 - k - 1] = temp;
    }
}

void SequenceAligner_free(SequenceAligner* aligner) {
    for (int i = 0; i <= aligner->m; i++) {
        free(aligner->dp[i]);
    }
    free(aligner->dp);
    free(aligner);
}

void main() {
    char* seq1 = "AGGTAB";
    char* seq2 = "GXTXAYB";
    SequenceAligner* aligner = SequenceAligner_init(seq1, seq2);
    calculate_score(aligner);
    char* align1;
    char* align2;
    traceback(aligner, &align1, &align2);
    printf("Aligned Sequence 1: %s\n", align1);
    printf("Aligned Sequence 2: %s\n", align2);
    SequenceAligner_free(aligner);
    free(align1);
    free(align2);
}