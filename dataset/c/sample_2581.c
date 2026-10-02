#include <stdio.h>
#include <string.h>

double calculate_similarity(char *seq1, char *seq2) {
    int score = 0;
    int length = strlen(seq1) < strlen(seq2) ? strlen(seq1) : strlen(seq2);
    for (int i = 0; i < length; i++) {
        if (seq1[i] == seq2[i]) {
            score += 1;
        }
    }
    return (double)score / length;
}

void find_best_alignment(char *sequences[], int num_sequences, char *best_pair1, char *best_pair2, double *max_score) {
    *max_score = 0;
    for (int i = 0; i < num_sequences; i++) {
        for (int j = i + 1; j < num_sequences; j++) {
            double score = calculate_similarity(sequences[i], sequences[j]);
            if (score > *max_score) {
                *max_score = score;
                strcpy(best_pair1, sequences[i]);
                strcpy(best_pair2, sequences[j]);
            }
        }
    }
}

int main() {
    char *sequences[] = {"ATCG", "ATCC", "AGCG", "ACCG"};
    int num_sequences = sizeof(sequences) / sizeof(sequences[0]);
    char best_pair1[5], best_pair2[5];
    double max_score;
    find_best_alignment(sequences, num_sequences, best_pair1, best_pair2, &max_score);
    printf("Best alignment: (%s, %s) with score: %f\n", best_pair1, best_pair2, max_score);
    return 0;
}