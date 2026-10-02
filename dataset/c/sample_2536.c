#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 100

typedef struct {
    char words[MAX_WORDS][MAX_WORD_LENGTH];
    int word_count;
} TextData;

void vectorize_text(const char* text, int vectors[MAX_WORDS][MAX_WORDS]) {
    char temp[MAX_WORD_LENGTH];
    int vocab[MAX_WORDS];
    int vocab_count = 0;
    int i = 0, j = 0;
    TextData td;
    td.word_count = 0;

    // Split text into words
    while (sscanf(text + i, "%s%n", temp, &j) == 1) {
        i += j;
        int found = 0;
        for (int k = 0; k < vocab_count; k++) {
            if (strcmp(td.words[vocab[k]], temp) == 0) {
                found = 1;
                break;
            }
        }
        if (!found) {
            vocab[vocab_count++] = td.word_count;
            strcpy(td.words[td.word_count++], temp);
        }
    }

    // Initialize vectors
    for (i = 0; i < MAX_WORDS; i++) {
        for (j = 0; j < MAX_WORDS; j++) {
            vectors[i][j] = 0;
        }
    }

    // Fill vectors
    i = 0;
    while (sscanf(text + i, "%s%n", temp, &j) == 1) {
        i += j;
        for (int k = 0; k < vocab_count; k++) {
            if (strcmp(td.words[vocab[k]], temp) == 0) {
                vectors[i][vocab[k]] = 1;
                break;
            }
        }
    }
}

void analyze_sequence(const char* sequence[], int result[MAX_WORDS][MAX_WORDS], int* result_rows) {
    int row = 0;
    for (int i = 0; sequence[i] != NULL; i++) {
        vectorize_text(sequence[i], result + row);
        row++;
    }
    *result_rows = row;
}

int main() {
    const char* data[] = {"hello world", "data science", "hello universe", NULL};
    int result[MAX_WORDS][MAX_WORDS];
    int result_rows;

    analyze_sequence(data, result, &result_rows);

    for (int i = 0; i < result_rows; i++) {
        for (int j = 0; j < MAX_WORDS; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}