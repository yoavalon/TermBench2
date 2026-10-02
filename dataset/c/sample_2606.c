#include <stdio.h>
#include <stdlib.h>

int* generate_sequence(int n) {
    int* sequence = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        sequence[i] = i * i + i + 1;
    }
    return sequence;
}

int** align_sequences(int* seq1, int len1, int* seq2, int len2) {
    int** alignment = (int**)malloc((len1 + 1) * sizeof(int*));
    for (int i = 0; i <= len1; i++) {
        alignment[i] = (int*)malloc((len2 + 1) * sizeof(int));
        for (int j = 0; j <= len2; j++) {
            alignment[i][j] = 0;
        }
    }
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            if (seq1[i - 1] == seq2[j - 1]) {
                alignment[i][j] = alignment[i - 1][j - 1] + 1;
            } else {
                alignment[i][j] = (alignment[i - 1][j] > alignment[i][j - 1]) ? alignment[i - 1][j] : alignment[i][j - 1];
            }
        }
    }
    return alignment;
}

int* find_longest_common_subsequence(int* seq1, int len1, int* seq2, int len2) {
    int** alignment_matrix = align_sequences(seq1, len1, seq2, len2);
    int* lcs = (int*)malloc((len1 + len2) * sizeof(int));
    int index = 0;
    while (len1 > 0 && len2 > 0) {
        if (seq1[len1 - 1] == seq2[len2 - 1]) {
            lcs[index++] = seq1[len1 - 1];
            len1--;
            len2--;
        } else if (alignment_matrix[len1 - 1][len2] > alignment_matrix[len1][len2 - 1]) {
            len1--;
        } else {
            len2--;
        }
    }
    for (int i = 0; i < index / 2; i++) {
        int temp = lcs[i];
        lcs[i] = lcs[index - i - 1];
        lcs[index - i - 1] = temp;
    }
    for (int i = index; i < len1 + len2; i++) {
        lcs[i] = 0;
    }
    return lcs;
}

void main() {
    int* seq1 = generate_sequence(10);
    int* seq2 = generate_sequence(12);
    int* lcs = find_longest_common_subsequence(seq1, 10, seq2, 12);
    for (int i = 0; lcs[i] != 0; i++) {
        printf("%d ", lcs[i]);
    }
    printf("\n");
}