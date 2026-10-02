#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compute_alignment_score(const char *seq1, const char *seq2, int matrix[4][4], int gap_penalty) {
    int m = strlen(seq1);
    int n = strlen(seq2);
    int score_matrix[m + 1][n + 1];
    for (int i = 0; i <= m; i++) {
        score_matrix[i][0] = i * gap_penalty;
    }
    for (int j = 0; j <= n; j++) {
        score_matrix[0][j] = j * gap_penalty;
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            int match = score_matrix[i - 1][j - 1] + matrix[seq1[i - 1] - 'A'][seq2[j - 1] - 'A'];
            int delete = score_matrix[i - 1][j] + gap_penalty;
            int insert = score_matrix[i][j - 1] + gap_penalty;
            score_matrix[i][j] = match > delete ? (match > insert ? match : insert) : (delete > insert ? delete : insert);
        }
    }
    return score_matrix[m][n];
}

void backtrack_alignment(const char *seq1, const char *seq2, int matrix[4][4], int gap_penalty, char *aligned_seq1, char *aligned_seq2) {
    int m = strlen(seq1);
    int n = strlen(seq2);
    int score_matrix[m + 1][n + 1];
    for (int i = 0; i <= m; i++) {
        score_matrix[i][0] = i * gap_penalty;
    }
    for (int j = 0; j <= n; j++) {
        score_matrix[0][j] = j * gap_penalty;
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            int match = score_matrix[i - 1][j - 1] + matrix[seq1[i - 1] - 'A'][seq2[j - 1] - 'A'];
            int delete = score_matrix[i - 1][j] + gap_penalty;
            int insert = score_matrix[i][j - 1] + gap_penalty;
            score_matrix[i][j] = match > delete ? (match > insert ? match : insert) : (delete > insert ? delete : insert);
        }
    }
    int i = m, j = n;
    int index1 = 0, index2 = 0;
    while (i > 0 || j > 0) {
        if (i > 0 && j > 0 && score_matrix[i][j] == score_matrix[i - 1][j - 1] + matrix[seq1[i - 1] - 'A'][seq2[j - 1] - 'A']) {
            aligned_seq1[index1++] = seq1[i - 1];
            aligned_seq2[index2++] = seq2[j - 1];
            i--;
            j--;
        } else if (i > 0 && score_matrix[i][j] == score_matrix[i - 1][j] + gap_penalty) {
            aligned_seq1[index1++] = seq1[i - 1];
            aligned_seq2[index2++] = '-';
            i--;
        } else if (j > 0 && score_matrix[i][j] == score_matrix[i][j - 1] + gap_penalty) {
            aligned_seq1[index1++] = '-';
            aligned_seq2[index2++] = seq2[j - 1];
            j--;
        }
    }
    aligned_seq1[index1] = '\0';
    aligned_seq2[index2] = '\0';
    for (int k = 0; k < index1 / 2; k++) {
        char temp = aligned_seq1[k];
        aligned_seq1[k] = aligned_seq1[index1 - k - 1];
        aligned_seq1[index1 - k - 1] = temp;
    }
    for (int k = 0; k < index2 / 2; k++) {
        char temp = aligned_seq2[k];
        aligned_seq2[k] = aligned_seq2[index2 - k - 1];
        aligned_seq2[index2 - k - 1] = temp;
    }
}

int main() {
    const char *seq1 = "ACGT";
    const char *seq2 = "ACGTA";
    int matrix[4][4] = {
        {2, -1, -1, -1},
        {-1, 2, -1, -1},
        {-1, -1, 2, -1},
        {-1, -1, -1, 2}
    };
    int gap_penalty = -1;
    int score = compute_alignment_score(seq1, seq2, matrix, gap_penalty);
    char aligned_seq1[100], aligned_seq2[100];
    backtrack_alignment(seq1, seq2, matrix, gap_penalty, aligned_seq1, aligned_seq2);
    printf("Alignment Score: %d\n", score);
    printf("Aligned Sequence 1: %s\n", aligned_seq1);
    printf("Aligned Sequence 2: %s\n", aligned_seq2);
    return 0;
}